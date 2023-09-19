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
	int j;
	char c;
	char *s;
	int d_i;
	int digits;
	int temp;
	va_list args;

	digits = 0;
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
			else if (*format == 'd' || *format == 'i')
			{
				d_i = va_arg(args, int);
				if (d_i < 0)
				{
					_putchar('-');
					d_i = -d_i;
				}
				temp = d_i;
				while (temp != 0)
				{
					temp /= 10;
					digits++;
				}

				for (j = 0; j < digits; j++)
				{
					_putchar('0' + (d_i % 10));
					d_i /= 10;
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
