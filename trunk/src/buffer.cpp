/*
 * =====================================================================================
 *
 *       Filename:  buffer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月01日 22时54分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zilong.Zhu (), zilong.whu@gmail.com
 *        Company:  edu.whu
 *
 * =====================================================================================
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"

static int nextPower2(int val)
{
	if (val < 0)
		return 1;
	if (val > (INT_MAX>>1) + 1)
		return val;
	int ret = 1;
	while (ret < val)
	{
		ret <<= 1;
	}
	return ret;
}

enum
{
	BUFFER_T_AUTO_FLAG = 1,
	BUFFER_T_TRUNC_FLAG = 2,
};

buffer_t::buffer_t(size_t initSize)
{
	_flags = BUFFER_T_AUTO_FLAG;
	_curSize = nextPower2(initSize);
	_buffer = (char *)malloc(_curSize);
	_current = _buffer;
}

buffer_t::buffer_t(char *buffer, size_t initSize)
{
	_flags = 0;
	_curSize = initSize;
	_buffer = buffer;
	_current = _buffer;
}

buffer_t::buffer_t(const buffer_t &o)
{
	_flags = o._flags;
	_curSize = o._curSize;
	if ((_flags & BUFFER_T_AUTO_FLAG) == 0)
	{
		_buffer = o._buffer;
		_current = o._current;
		return ;
	}
	/* auto buffer */
	if (o._buffer == NULL)
	{
		_current = _buffer = NULL;
		return ;
	}
	_buffer = (char *)malloc(_curSize);
	if (_buffer && o._current > o._buffer)
	{
		memcpy(_buffer, o._buffer, o._current - o._buffer);
		_current = _buffer + (o._current - o._buffer);
		return ;
	}
	_current = _buffer;
}

buffer_t::~buffer_t()
{
	if ((_flags & BUFFER_T_AUTO_FLAG) && _buffer)
		free(_buffer);
	_flags = 0;
	_curSize = 0;
	_current = _buffer = NULL;
}

buffer_t &buffer_t::operator =(const buffer_t &o)
{
	buffer_t cpy(o);
	this->swap(cpy);
	return *this;
}

buffer_t &buffer_t::append(const char *fmt, va_list va)
{
	if (!_buffer)
	{
		_flags |= BUFFER_T_TRUNC_FLAG;
		return *this;
	}
	const size_t left_sz = _curSize - (_current - _buffer);
	int ret = vsnprintf(_current, left_sz, fmt, va);
	if (ret < 0) return *this;
	if (ret < left_sz)
	{
		_current += ret;
		return *this;
	}
	char *buf;
	int next_sz;
	if ((_flags & BUFFER_T_AUTO_FLAG) == 0)  /* static buffer */
		goto TRUNC;
	next_sz = nextPower2(_curSize + ret + 1 - left_sz);
	if (next_sz <= _curSize)
		goto TRUNC;
	buf = (char *)malloc(next_sz);
	if (!buf)
		goto TRUNC;
	if (_current > _buffer)
		memcpy(buf, _buffer, _current - _buffer);
	_current = buf + (_current - _buffer);
	free(_buffer);
	_buffer = buf;
	_curSize = next_sz;

	return this->append(fmt, va);
TRUNC:
	_flags |= BUFFER_T_TRUNC_FLAG;
	_current += left_sz - 1;
	return *this;
}
