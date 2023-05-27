#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * printf - function to print output according to a format.
 *
 * @format: character string.
 *
 * Return: returns the number of characters printed.
 *
 */

int _printf(const char *format, ...)
{
	int i = 0;
	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		i++;
	}
	write(1, format, i);
	return (i);
}
