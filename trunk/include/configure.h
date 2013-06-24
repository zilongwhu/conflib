/*
 * =====================================================================================
 *
 *       Filename:  configure.h
 *
 *    Description:  configure header file
 *
 *        Version:  1.0
 *        Created:  2012年09月01日 22时11分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zilong.Zhu (), zilong.whu@gmail.com
 *        Company:  edu.whu
 *
 * =====================================================================================
 */

#ifndef __CONFIGURE_HEADER_H__
#define __CONFIGURE_HEADER_H__

#include <map>
#include <string>

class Config
{
    public:
        Config(const char *path, const char *file)
            :_path(path), _file(file)
        { }
        ~Config() { }

        int parse();

        const std::string &operator[](const std::string &key) const
        {
            std::map<std::string, std::string>::const_iterator it = _confs.find(key);
            if (it != _confs.end())
            {
                return it->second;
            }
            return "";
        }
    private:
        const std::string _path;
        const std::string _file;

        std::map<std::string, std::string> _confs;
};

#endif
