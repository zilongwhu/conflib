/*
 * =====================================================================================
 *
 *       Filename:  any.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月04日 23时41分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zilong.Zhu (), zilong.whu@gmail.com
 *        Company:  edu.whu
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include "any.h"

Any::Any() { _type = UNSET; }

Any::~Any()
{
	switch(_type)
	{
	case STRING_TYPE:
		if (_value._string_value)
			delete _value._string_value;
		_value._string_value = NULL;
		break;
	case DICT_TYPE:
		if (_value._dict_value)
			delete _value._dict_value;
		_value._dict_value = NULL;
		break;
	}
}

Any::Any(const Any &o)
{
	switch(_type)
	{
	case CHAR_TYPE:
		_value._char_value = o._value._char_value;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = o._value._uchar_value;
		break;
	case SHORT_TYPE:
		_value._short_value = o._value._short_value;
		break;
	case USHORT_TYPE:
		_value._ushort_value = o._value._ushort_value;
		break;
	case INT_TYPE:
		_value._int_value = o._value._int_value;
		break;
	case UINT_TYPE:
		_value._uint_value = o._value._uint_value;
		break;
	case LONG_TYPE:
		_value._long_value = o._value._long_value;
		break;
	case ULONG_TYPE:
		_value._ulong_value = o._value._ulong_value;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = o._value._longlong_value;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = o._value._ulonglong_value;
		break;
	case DOUBLE_TYPE:
		_value._double_value = o._value._double_value;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = o._value._longdouble_value;
		break;
	case STRING_TYPE:
		if (o._value._string_value)
			_value._string_value = new(std::nothrow) std::string(*o._value._string_value);
		else
			_value._string_value = NULL;
		break;
	case DICT_TYPE:
		if (o._value._dict_value)
			_value._dict_value = new(std::nothrow) dict_type(*o._value._dict_value);
		else
			_value._dict_value = NULL;
		break;
	}
}

void Any::swap(Any &o)
{
	{
		int tmp = _type;
		_type = o._type;
		o._type = tmp;
	}
	{
		char tmp[sizeof _value];
		memcpy(&tmp, &_value, sizeof _value);
		memcpy(&_value, &o._value, sizeof _value);
		memcpy(&o._value, tmp, sizeof _value);
	}
}

#define ANY_ASSGIN_OP(type, TYPE, name, fmt) \
Any &Any::operator=(type val)\
{\
	switch(_type)\
	{\
	case UNSET:\
		_type = TYPE;\
		_value.name = val;\
		break;\
	case CHAR_TYPE:\
		_value._char_value = static_cast<char>(val);\
		break;\
	case UCHAR_TYPE:\
		_value._uchar_value = static_cast<unsigned char>(val);\
		break;\
	case SHORT_TYPE:\
		_value._short_value = static_cast<short>(val);\
		break;\
	case USHORT_TYPE:\
		_value._ushort_value = static_cast<unsigned short>(val);\
		break;\
	case INT_TYPE:\
		_value._int_value = static_cast<int>(val);\
		break;\
	case UINT_TYPE:\
		_value._uint_value = static_cast<unsigned int>(val);\
		break;\
	case LONG_TYPE:\
		_value._long_value = static_cast<long>(val);\
		break;\
	case ULONG_TYPE:\
		_value._ulong_value = static_cast<unsigned long>(val);\
		break;\
	case LONGLONG_TYPE:\
		_value._longlong_value = static_cast<long long>(val);\
		break;\
	case ULONGLONG_TYPE:\
		_value._ulonglong_value = static_cast<unsigned long long>(val);\
		break;\
	case DOUBLE_TYPE:\
		_value._double_value = static_cast<double>(val);\
		break;\
	case LONGDOUBLE_TYPE:\
		_value._longdouble_value = static_cast<long double>(val);\
		break;\
	case STRING_TYPE:\
		{\
			char buf[128];\
			if (::snprintf(buf, sizeof buf, fmt, val) > 0)\
            {\
                if (_value._string_value)\
                    *_value._string_value = buf;\
                else\
                    _value._string_value = new (std::nothrow) std::string(buf);\
            }\
		}\
		break;\
	}\
	return *this;\
}

ANY_ASSGIN_OP(char, CHAR_TYPE, _char_value, "%c");
ANY_ASSGIN_OP(short, SHORT_TYPE, _short_value, "%hd");
ANY_ASSGIN_OP(int, INT_TYPE, _int_value, "%d");
ANY_ASSGIN_OP(long, LONG_TYPE, _long_value, "%ld");
ANY_ASSGIN_OP(long long, LONGLONG_TYPE, _longlong_value, "%lld");

ANY_ASSGIN_OP(unsigned char, UCHAR_TYPE, _uchar_value, "%hhu");
ANY_ASSGIN_OP(unsigned short, USHORT_TYPE, _ushort_value, "%hu");
ANY_ASSGIN_OP(unsigned int, UINT_TYPE, _uint_value, "%u");
ANY_ASSGIN_OP(unsigned long, ULONG_TYPE, _ulong_value, "%lu");
ANY_ASSGIN_OP(unsigned long long, ULONGLONG_TYPE, _ulonglong_value, "%llu");

ANY_ASSGIN_OP(double, DOUBLE_TYPE, _double_value, "%lf");
ANY_ASSGIN_OP(long double, LONGDOUBLE_TYPE, _longdouble_value, "%Lf");

#undef ANY_ASSIGN_OP
