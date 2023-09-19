#include "main.h"
#include <stdio.h>
#include <stdarg.h>

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
	va_list args;

	va_start(args, format);

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
				while (*s != '\0')
				{
					_putchar(*s);
					s++;
					i++;
				}
			}
			else if (*format == '%')
			{
				_putchar(*format);
				i++;
			}
			else
			{
				_putchar('%');
				putchar(*format);
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
