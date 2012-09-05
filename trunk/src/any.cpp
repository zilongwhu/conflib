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

#include "any.h"

Any::Any(AnyType type)
	: _type(type)
{
	switch(_type)
	{
	case UNSET:
		break;
	case CHAR_TYPE:
		_value._char_value = '\0';
		break;
	case UCHAR_TYPE:
		_value._uchar_value = '\0';
		break;
	case SHORT_TYPE:
		_value._short_value = 0;
		break;
	case USHORT_TYPE:
		_value._ushort_value = 0;
		break;
	case INT_TYPE:
		_value._int_value = 0;
		break;
	case UINT_TYPE:
		_value._uint_value = 0;
		break;
	case LONG_TYPE:
		_value._long_value = 0;
		break;
	case ULONG_TYPE:
		_value._ulong_value = 0;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = 0;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = 0;
		break;
	case DOUBLE_TYPE:
		_value._double_value = 0.0;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = 0.0;
		break;
	case STRING_TYPE:
		_value._string_value = new(std::nothrow) std::string;
		break;
	case DICT_TYPE:
		_value._dict_value = new(std::nothrow) dict_type;
		break;
	}
}

Any::~Any()
{
	switch(_type)
	{
	case UNSET:
		break;
	case CHAR_TYPE:
		_value._char_value = '\0';
		break;
	case UCHAR_TYPE:
		_value._uchar_value = '\0';
		break;
	case SHORT_TYPE:
		_value._short_value = 0;
		break;
	case USHORT_TYPE:
		_value._ushort_value = 0;
		break;
	case INT_TYPE:
		_value._int_value = 0;
		break;
	case UINT_TYPE:
		_value._uint_value = 0;
		break;
	case LONG_TYPE:
		_value._long_value = 0;
		break;
	case ULONG_TYPE:
		_value._ulong_value = 0;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = 0;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = 0;
		break;
	case DOUBLE_TYPE:
		_value._double_value = 0.0;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = 0.0;
		break;
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
	case UNSET:
		break;
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
		AnyType tmp = _type;
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

Any &Any::operator=(char val)
{
	switch(_type)
	{
	case UNSET:
		_type = CHAR_TYPE;
		_value._char_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char tmp[2];
			tmp[0] = val;
			tmp[1] = '\0';
			*_value._string_value = tmp;
		}
		break;
	case DICT_TYPE:
		throw std::exception("set char value to dict_type");
		break;
	}
	return *this;
}

Any &Any::operator=(unsigned char val)
{
	switch(_type)
	{
	case UNSET:
		_type = UCHAR_TYPE;
		_value._uchar_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char buf[128];
			if (_snprintf(buf, sizeof buf, "%hhu", val) > 0)
				*_value._string_value = buf;
			else throw std::exception("snprintf error");
		}
		break;
	case DICT_TYPE:
		throw std::exception("set unsigned char value to dict_type");
		break;
	}
	return *this;
}

Any &Any::operator=(short val)
{
	switch(_type)
	{
	case UNSET:
		_type = SHORT_TYPE;
		_value._short_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char buf[128];
			if (_snprintf(buf, sizeof buf, "%hd", val) > 0)
				*_value._string_value = buf;
			else throw std::exception("snprintf error");
		}
		break;
	case DICT_TYPE:
		throw std::exception("set short value to dict_type");
		break;
	}
	return *this;
}

Any &Any::operator=(unsigned short val)
{
	switch(_type)
	{
	case UNSET:
		_type = USHORT_TYPE;
		_value._ushort_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char buf[128];
			if (_snprintf(buf, sizeof buf, "%hu", val) > 0)
				*_value._string_value = buf;
			else throw std::exception("snprintf error");
		}
		break;
	case DICT_TYPE:
		throw std::exception("set unsigned short value to dict_type");
		break;
	}
	return *this;
}

Any &Any::operator=(int val)
{
	switch(_type)
	{
	case UNSET:
		_type = INT_TYPE;
		_value._int_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char buf[128];
			if (_snprintf(buf, sizeof buf, "%d", val) > 0)
				*_value._string_value = buf;
			else throw std::exception("snprintf error");
		}
		break;
	case DICT_TYPE:
		throw std::exception("set int value to dict_type");
		break;
	}
	return *this;
}

Any &Any::operator=(unsigned int val)
{
	switch(_type)
	{
	case UNSET:
		_type = UINT_TYPE;
		_value._uint_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char buf[128];
			if (_snprintf(buf, sizeof buf, "%u", val) > 0)
				*_value._string_value = buf;
			else throw std::exception("snprintf error");
		}
		break;
	case DICT_TYPE:
		throw std::exception("set unsigned int value to dict_type");
		break;
	}
	return *this;
}

Any &Any::operator=(long val)
{
	switch(_type)
	{
	case UNSET:
		_type = LONG_TYPE;
		_value._long_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char buf[128];
			if (_snprintf(buf, sizeof buf, "%ld", val) > 0)
				*_value._string_value = buf;
			else throw std::exception("snprintf error");
		}
		break;
	case DICT_TYPE:
		throw std::exception("set long value to dict_type");
		break;
	}
	return *this;
}

Any &Any::operator=(unsigned long val)
{
	switch(_type)
	{
	case UNSET:
		_type = ULONG_TYPE;
		_value._ulong_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char buf[128];
			if (_snprintf(buf, sizeof buf, "%lu", val) > 0)
				*_value._string_value = buf;
			else throw std::exception("snprintf error");
		}
		break;
	case DICT_TYPE:
		throw std::exception("set unsigned long value to dict_type");
		break;
	}
	return *this;
}

Any &Any::operator=(long long val)
{
	switch(_type)
	{
	case UNSET:
		_type = LONGLONG_TYPE;
		_value._longlong_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char buf[128];
			if (_snprintf(buf, sizeof buf, "%lld", val) > 0)
				*_value._string_value = buf;
			else throw std::exception("snprintf error");
		}
		break;
	case DICT_TYPE:
		throw std::exception("set long long value to dict_type");
		break;
	}
	return *this;
}

Any &Any::operator=(unsigned long long val)
{
	switch(_type)
	{
	case UNSET:
		_type = ULONGLONG_TYPE;
		_value._ulonglong_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char buf[128];
			if (_snprintf(buf, sizeof buf, "%llu", val) > 0)
				*_value._string_value = buf;
			else throw std::exception("snprintf error");
		}
		break;
	case DICT_TYPE:
		throw std::exception("set unsigned long long value to dict_type");
		break;
	}
	return *this;
}

Any &Any::operator=(double val)
{
	switch(_type)
	{
	case UNSET:
		_type = DOUBLE_TYPE;
		_value._double_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char buf[128];
			if (_snprintf(buf, sizeof buf, "%f", val) > 0)
				*_value._string_value = buf;
			else throw std::exception("snprintf error");
		}
		break;
	case DICT_TYPE:
		throw std::exception("set double value to dict_type");
		break;
	}
	return *this;
}

Any &Any::operator=(long double val)
{
	switch(_type)
	{
	case UNSET:
		_type = LONGDOUBLE_TYPE;
		_value._longdouble_value = val;
		break;
	case CHAR_TYPE:
		_value._char_value = val;
		break;
	case UCHAR_TYPE:
		_value._uchar_value = val;
		break;
	case SHORT_TYPE:
		_value._short_value = val;
		break;
	case USHORT_TYPE:
		_value._ushort_value = val;
		break;
	case INT_TYPE:
		_value._int_value = val;
		break;
	case UINT_TYPE:
		_value._uint_value = val;
		break;
	case LONG_TYPE:
		_value._long_value = val;
		break;
	case ULONG_TYPE:
		_value._ulong_value = val;
		break;
	case LONGLONG_TYPE:
		_value._longlong_value = val;
		break;
	case ULONGLONG_TYPE:
		_value._ulonglong_value = val;
		break;
	case DOUBLE_TYPE:
		_value._double_value = val;
		break;
	case LONGDOUBLE_TYPE:
		_value._longdouble_value = val;
		break;
	case STRING_TYPE:
		if (_value._string_value)
		{
			char buf[128];
			if (_snprintf(buf, sizeof buf, "%lf", val) > 0)
				*_value._string_value = buf;
			else throw std::exception("snprintf error");
		}
		break;
	case DICT_TYPE:
		throw std::exception("set long double value to dict_type");
		break;
	}
	return *this;
}
