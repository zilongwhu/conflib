/*
 * =====================================================================================
 *
 *       Filename:  buffer.h
 *
 *    Description:  appendable buffer
 *
 *        Version:  1.0
 *        Created:  2012年09月01日 22时22分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zilong.Zhu (), zilong.whu@gmail.com
 *        Company:  edu.whu
 *
 * =====================================================================================
 */

#ifndef __APPENDABLE_BUFFER_H__
#define __APPENDABLE_BUFFER_H__

#include <stdint.h>
#include <stdarg.h>
#include <linux/types.h>

class buffer_t
{
	public:
		buffer_t(size_t initSize = 1024); /* auto buffer */
		buffer_t(char *buffer, size_t initSize); /* static buffer */
		buffer_t(const buffer_t &o);

		~buffer_t();

		buffer_t &operator =(const buffer_t &o);

		buffer_t &operator +=(char val)
		{
			this->append("%hhd", val);
			return *this;
		}
		buffer_t &operator +=(unsigned char val)
		{
			this->append("%hhu", val);
			return *this;
		}
		buffer_t &operator +=(short val)
		{
			this->append("%hd", val);
			return *this;
		}
		buffer_t &operator +=(unsigned short val)
		{
			this->append("%hu", val);
			return *this;
		}
		buffer_t &operator +=(int val)
		{
			this->append("%d", val);
			return *this;
		}
		buffer_t &operator +=(unsigned int val)
		{
			this->append("%u", val);
			return *this;
		}
		buffer_t &operator +=(long val)
		{
			this->append("%ld", val);
			return *this;
		}
		buffer_t &operator +=(unsigned long val)
		{
			this->append("%lu", val);
			return *this;
		}
		buffer_t &operator +=(long long val)
		{
			this->append("%lld", val);
			return *this;
		}
		buffer_t &operator +=(unsigned long long val)
		{
			this->append("%llu", val);
			return *this;
		}
		buffer_t &operator +=(float val)
		{
			return this->operator +=((double)val);
		}
		buffer_t &operator +=(double val)
		{
			this->append("%f", val);
			return *this;
		}
		buffer_t &operator +=(long double val)
		{
			this->append("%Lf", val);
			return *this;
		}
		buffer_t &operator +=(const char *str)
		{
			if (str) this->append("%s", str);
			return *this;
		}
		buffer_t &operator +=(const buffer_t &o)
		{
			this->append("%s", o.c_str());
			return *this;
		}

		buffer_t &put_char(char ch)
		{
			this->append("%c", ch);
			return *this;
		}

		buffer_t &print_hex(unsigned char ch)
		{
			this->append("%hhX", ch);
			return *this;
		}

		buffer_t &append(const char *fmt, ...)
		{
			va_list va;
			va_start(va, fmt);
			this->append(fmt, va);
			va_end(va);
			return *this;
		}

		const char *c_str() const
		{
			if (!_current)
				return "";
			*_current = '\0';
			return _buffer;
		}

		void swap(buffer_t &o)
		{
			char *tmp = _buffer;
			_buffer = o._buffer;
			o._buffer = tmp;
			
			tmp = _current;
			_current = o._current;
			o._current = tmp;

			size_t sz = _curSize;
			_curSize = o._curSize;
			o._curSize = sz;

			uint32_t flag = _flags;
			_flags = o._flags;
			o._flags = flag;
		}
	private:
		buffer_t &append(const char *fmt, va_list va);
	private:
		char *_buffer;
		char *_current;
		size_t _curSize;
		uint32_t _flags;
};

#endif
