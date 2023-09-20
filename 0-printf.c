#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

/**
 * _printfInt - produce output for integers
 * @d_i: integer
 * Return: the number of characters printed
 */

int _printfInt(int d_i)
{
	char buffer[12];
	int temp;
	int digits;
	int index;

	digits = 0;
	index = 0;
	if (d_i == 0)
	{
		_putchar('0');
		return (1);
	}
	if (d_i < 0)
	{
		_putchar('-');
		if (d_i == INT_MIN)
		{
			buffer[index++] = d_i % 10;
			d_i = -(d_i / 10);
		}
		else
		{
			d_i = -d_i;
			digits++;
		}
	}
	temp = d_i;
	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}

	while (d_i > 0)
	{
		buffer[index++] = '0' + (d_i % 10);
		d_i /= 10;
	}
	while (index > 0)
	{
		_putchar(buffer[--index]);
	}
	return (digits);
}

/**
 * _printf - produces output according to a format
 * @format: a format character string that handles output format
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i;
	char c;
	char *s;
	int d_i;
	va_list args;

	i = 0;	
	if (format == NULL)
	{
		return (0);
	}
	va_start(args, format);
	if (format[1] == '\0')
	{
		_putchar(format[0]);
		return (1);
	}

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				_putchar(c);
				i++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				if (s == NULL)
				{
					s = "(null)";
				}
				while (*s != '\0')
				{
					_putchar(*s);
					s++;
					i++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				d_i = va_arg(args, int);
				i += _printfInt(d_i);
			}
			else if (*format == '%')
			{
				_putchar(*format);
				i++;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				i += 2;
			}
		}
		else
		{
			_putchar(*format);
			i++;
		}
		format++;
	}
	va_end(args);
	return (i);
}
