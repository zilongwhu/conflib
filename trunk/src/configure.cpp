/*
 * =====================================================================================
 *
 *       Filename:  configure.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年06月24日 22时57分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "configure.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <string.h>

static char *str_trim(char *str)
{
    while (*str)
    {
        if (!::isspace(*str))
            break;
        ++str;
    }
    if (str[0] == '\0')
        return str;
    char *ret = str;
    while (*str) ++str;
    for (--str; ::isspace(*str); --str) ;
    str[1] = '\0';
    return ret;
}

int Config::parse()
{
    std::ostringstream os;
    os << _path << "/" << _file;
    std::ifstream in(os.str().c_str());
    if (!in)
    {
        return -1;
    }
    char line[1024];
    while (in.getline(line, sizeof line))
    {
        char *value = ::strchr(line, ':');
        if (NULL == value)
            continue;
        *value++ = '\0';
        char *key = str_trim(line);
        if ('#' == key[0])
            continue;
        value = str_trim(value);
        _confs[key] = value;
    }
    return 0;
}
