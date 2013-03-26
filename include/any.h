/*
 * =====================================================================================
 *
 *       Filename:  any.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月04日 23时41分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zilong.Zhu (), zilong.whu@gmail.com
 *        Company:  edu.whu
 *
 * =====================================================================================
 */

#ifndef __ANY_TYPE_H__
#define __ANY_TYPE_H__

#include <map>
#include <string>

class Any
{
	public:
		typedef std::map<std::string, Any> dict_type;
	public:
		Any();
		Any(const Any &o);
		~Any();

        void swap(Any &o);

		Any &operator =(const Any &o);

		Any &operator =(char val);
		Any &operator =(unsigned char val);
		Any &operator =(short val);
		Any &operator =(unsigned short val);
		Any &operator =(int val);
		Any &operator =(unsigned int val);
		Any &operator =(long val);
		Any &operator =(unsigned long val);
		Any &operator =(long long val);
		Any &operator =(unsigned long long val);
		Any &operator =(double val);
		Any &operator =(long double val);
		Any &operator =(const char *val);
		Any &operator =(const std::string &val);
		Any &operator =(const dict_type &val);

		char get_char_value(char def='\0') const;
		unsigned char get_uchar_value(unsigned char def='\0') const;
		short get_short_value(short def=0) const;
		unsigned short get_ushort_value(unsigned short def=0) const;
		int get_int_value(int def=0) const;
		unsigned int get_uint_value(unsigned int def=0) const;
		long get_long_value(long def=0) const;
		unsigned long get_ulong_value(unsigned long def=0) const;
		long long get_longlong_value(long long def=0) const;
		unsigned long get_ulonglong_value(unsigned long long def=0) const;
		double get_double_value(double def=0.0) const;
		long double get_longdouble_value(long double def=0.0) const;
		bool get_string_value(std::string &val, const char *def="") const;
		bool get_dict_value(dict_type &val) const;
	private:
		enum
		{
			UNSET = 0,
			CHAR_TYPE,
			UCHAR_TYPE,
			SHORT_TYPE,
			USHORT_TYPE,
			INT_TYPE,
			UINT_TYPE,
			LONG_TYPE,
			ULONG_TYPE,
			LONGLONG_TYPE,
			ULONGLONG_TYPE,
			DOUBLE_TYPE,
			LONGDOUBLE_TYPE,
			STRING_TYPE,
			DICT_TYPE,
		};
		int _type;
		union
		{
			char _char_value;
			short _short_value;
			int _int_value;
			long _long_value;
			long long _longlong_value;

			unsigned char _uchar_value;
			unsigned short _ushort_value;
			unsigned int _uint_value;
			unsigned long _ulong_value;
			unsigned long long _ulonglong_value;

			double _double_value;
			long double _longdouble_value;

			std::string *_string_value;
			dict_type *_dict_value;
		} _value;
};

#endif
