#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_format - main
 * @arg: input
 * @format: input
 * Return: count
 */
int print_format(const char *format, va_list arg)
{
	int i = 0, len = 0;

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			len++;
		}
		else
		{
			i++;
			switch (format[i])
			{
				case 'c':
					{
						len += c_handle(arg);
						break;
					}
				case 's':
					{
						len += s_handle(arg);
						break;
					}
				case '%':
					{
						len += percent_handle(arg);
						break;
					}
				case 'd':
				case 'i':
					{
						len += d_handle(arg);
						break;
					}
				case 'b':
					{
						len += b_handle(arg);
						break;
					}
				default:
					{
						putchar('%');
						putchar(format[i]);
						len += 2;
					}
			}
		}
		i++;
	}
	return (len);
}
