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
#include <stdarg.h>
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

buffer_t::buffer_t(size_t initSize)
{
	_truncFlag = 0;
	_curSize = nextPower2(initSize);
	_buffer = (char *)malloc(_curSize);
	_current = _buffer;
}

buffer_t::buffer_t(const buffer_t &o)
{
	_truncFlag = o._truncFlag;
	_curSize = o._curSize;
	if (o._buffer)
	{
		_buffer = (char *)malloc(_curSize);
		if (_buffer && o._current > o._buffer)
		{
			memcpy(_buffer, o._buffer, o._current - o._buffer);
			_current = (o._current - o._buffer) + _buffer;
		}
		else
		{
			_current = _buffer;
		}
	}
	else
	{
		_current = _buffer = NULL;
	}
}

buffer_t::~buffer_t()
{
	_truncFlag = 0;
	_curSize = 0;
	_current = _buffer = NULL;
}

buffer_t &buffer_t::operator =(const buffer_t &o)
{
	buffer_t cpy(o);
	this->swap(cpy);
	return *this;
}

buffer_t &buffer_t::append(const char *fmt, ...)
{
	if (!_buffer)
	{
		_truncFlag |= 1;
		return *this;
	}
	const size_t left_sz = _curSize - (_current - _buffer);
	va_list va;
	va_start(va, fmt);
	int ret = vsnprintf(_current, left_sz, fmt, va);
	va_end(va);
	if (ret < 0)
	{
		return *this;
	}
	if (ret < left_sz)
	{
		_current += ret;
		return *this;
	}
	int next_sz = nextPower2(_curSize + ret + 1 - left_sz);
	if (next_sz <= _curSize)
	{
		_truncFlag |= 1;
		_current += left_sz - 1;
		return *this;
	}
	char *buf = (char *)malloc(next_sz);
	if (!buf)
	{
		_truncFlag |= 1;
		_current += left_sz - 1;
		return *this;
	}
	if (_current > _buffer)
		memcpy(buf, _buffer, _current - _buffer);
	_current = buf + (_current - _buffer);
	free(_buffer);
	_buffer = buf;
	_curSize = next_sz;

	va_start(va, fmt);
	this->append(fmt, va);
	va_end(va);

	return *this;
}
