#include <stdio.h>
#include "main.h"
#include "printf.c"
#include <stdarg.h>

/**
 * print_format - print format
 * @format: pointer to the format string.
 * @arg: argument.
 * Return: number of characters
 */

int print_format(const char *format, va_list arg)
{
	int len = 0;

	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{

			i++;
			if (format[i] == 'b')
			{
				unsigned int num = va_arg(arg, unsigned int);

				print_binary(num);
				len += sizeof(num);
			}
			else
			{
				/* handle other conversion speciiers */
			}
		}
		else
		{
			putchar(format[i]);
			len++;
		}
		i++;
	}
		return (len);
}

