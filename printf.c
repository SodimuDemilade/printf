#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

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
	char c;
	char *s;
	va_list list;
	int count = 0;
	
	va_start(list, format);
	while(*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
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
		else
		{
			putchar (*format);
			count++;
		}
		format++;
		}
		va_end(list);
		return count;
	}
