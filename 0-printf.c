#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

/**
 * _printStr - produce output for strings
 * @s: string
 * Return: the number of characters printed
 */

int _printStr(char *s)
{
	int digits;

	digits = 0;
	if (s == NULL)
	{
		s = "(null)";
	}
	while (*s != '\0')
	{
		_putchar(*s++);
		digits++;
	}
	return (digits);
}

/**
 * _printfInt - produce output for integers
 * @d_i: integer
 * Return: the number of characters printed
 */

int _printfInt(int d_i)
{
	char buffer[12];
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
		if (d_i == INT_MIN || d_i == LONG_MIN)
		{
			buffer[index++] = '8';
			d_i = -(d_i / 10);
		}
		else
		{
			d_i = -d_i;
			digits++;
		}
	}
	while (d_i > 0)
	{
		buffer[index++] = '0' + (d_i % 10);
		d_i /= 10;
		digits++;
	}
	while (index > 0)
	{
		_putchar(buffer[--index]);
	}
	return (digits);
}

/**
 * _printfFormat - produce formatted output
 * @format: a format character string to handle output format
 * @args: argumenst passed
 * Return: the number of characters printed
 */

int _printfFormat(const char *format, va_list args)
{
	int i;
	char c;
	char *s;
	int d_i;

	i = 0;
	if (*format == 'c')
	{
		c = va_arg(args, int);
		_putchar(c);
		i++;
	}
	else if (*format == 's')
	{
		s = va_arg(args, char *);
		i += _printStr(s);
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
	return (i);
}

/**
 * _printf - produces output
 * @format: a format character string that handles output format
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i;
	va_list args;

	i = 0;
	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				return (-1);
			}
			i += _printfFormat(format, args);
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
