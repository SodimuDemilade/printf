#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * select_format - select the format specifier.
 *
 * @list: the list.
 *
 * @format: the character string.
 *
 */
void select_format(va_list list, const char **format)
{
	char *s;
	char c;
	int count = 0;

	switch (**format)
	{
		case 'c': {
				c = (char)va_arg(list, int);
				putchar(c);
				count++;
				break;
			}
		case 's': {
				s = va_arg(list, char *);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
				break;
				}
		case '%': {
				putchar('%');
				count++;
				break;
				}
	}
}

/**
 * _printf - function to print output according to a format.
 *
 * @format: character string.
 *
 * Return: returns the number of characters printed.
 *
 */

int _printf(const char *format, ...)
{
	va_list list;
	int count = 0;

	va_start(list, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			select_format(list, &format);
		}
		else
		{
			putchar (*format);
			count++;
		}
		format++;
		}
		va_end(list);
		return (count);
	}
