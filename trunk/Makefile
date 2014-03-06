all: libconf.a tester

src/buffer.o: include/buffer.h src/buffer.cpp
	g++ -g -Wall -Iinclude -c src/buffer.cpp -o src/buffer.o
src/configure.o: include/configure.h src/configure.cpp
	g++ -g -Wall -Iinclude -c src/configure.cpp -o src/configure.o
libconf.a: src/buffer.o src/configure.o
	ar crs $@ $^

tester: src/main.cpp libconf.a
	g++ -g -Wall -Iinclude src/main.cpp -Xlinker "-(" libconf.a -Xlinker "-)" -o tester
clean:
	rm -rf tester
	rm -rf src/*.o
	rm -rf conflib.a
