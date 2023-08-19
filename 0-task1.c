#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_format - format
 *
 * @format: input
 *
 * @arg: check
 *
 * Return: return count.
 *
 */

int print_format(const char *format, va_list arg)
{
	char *s;
	int i = 0, count = 0;

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
			i++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				putchar(va_arg(arg, int));
				count++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(arg, char *);
				while (*s != '\0')
				{
					putchar(*s);
					count++;
					s++;
				}
			}
			else if (format[i] == '%')
			{
				putchar('%');
				count++;
			}
			i++;
		}
	}
	return (count);
}

/**
 * _printf - function to print output.
 *
 * @format: input.
 *
 * Return: character length.
 *
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int len;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	len = print_format(format, arg);
	va_end(arg);
	return (len);
}
