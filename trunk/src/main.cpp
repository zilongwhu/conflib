/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月02日 00时31分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zilong.Zhu (), zilong.whu@gmail.com
 *        Company:  edu.whu
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "buffer.h"
#include "configure.h"

int main(int argc, char *argv[])
{
	buffer_t buf;
	buf+=10;
	buf.put_char(' ');
	buf+=10.12345;
	buf.put_char(' ');
	for (int i=0; i<16;++i)
		buf.print_hex(i);
	printf("%s\n", buf.c_str());

	char tmp[256];
	buffer_t buf2(tmp, sizeof tmp);
	buf2 += 100;
	buf2 += " abcdefg";
	printf("%s\n", buf2.c_str());

	buffer_t buf3(4);
	buf3 += 333;
	buf3 += " 666";
	printf("%s\n", buf3.c_str());

	buffer_t buf4 = buf;
	buffer_t buf5 = buf2;
	buffer_t buf6 = buf3;
	printf("%s\n", buf4.c_str());
	printf("%s\n", buf5.c_str());
	printf("%s\n", buf6.c_str());

    Config conf("./conf", "test.conf");
    conf.parse();
    printf("abc=[%s]\n", conf["abc"].c_str());
    printf("err=[%s]\n", conf["err"].c_str());
    printf("key err=[%s]\n", conf["key err"].c_str());
	return 0;
}
