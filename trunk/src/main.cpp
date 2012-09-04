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
	return 0;
}
