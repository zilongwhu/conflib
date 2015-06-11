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
#include <exception>
#include <stdlib.h>

class KeyNotExistException: public std::exception
{
    public:
        KeyNotExistException(const std::string &key) throw()
            : m_message(key + " not exist")
        { }
        ~KeyNotExistException() throw() { }

        const char *what() const throw()
        {
            return m_message.c_str();
        }
    private:
        const std::string m_message;
};

class Config
{
    public:
        Config(const char *path, const char *file)
            :_path(path), _file(file)
        { }
        ~Config() { }

        int parse();

        std::string operator[](const std::string &key) const
        {
            std::string value;
            if (this->get(key, value))
            {
                return value;
            }
            throw KeyNotExistException(key);
        }

        bool get(const std::string &key, std::string &value) const
        {
            std::map<std::string, std::string>::const_iterator it = _confs.find(key);
            if (it != _confs.end())
            {
                value = it->second;
                return true;
            }
            return false;
        }

        bool get(const std::string &key, int &value) const
        {
            std::string strvalue;
            if (this->get(key, strvalue))
            {
                value = atoi(strvalue.c_str());
                return true;
            }
            return false;
        }

        bool get(const std::string &key, double &value) const
        {
            std::string strvalue;
            if (this->get(key, strvalue))
            {
                value = atof(strvalue.c_str());
                return true;
            }
            return false;
        }
    private:
        const std::string _path;
        const std::string _file;

        std::map<std::string, std::string> _confs;
};

#endif
