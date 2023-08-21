#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - main
 *
 * @format: input
 *
 * Return: count
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
