#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf- prints conversion specifier.
 * @format: string format.
 * @...:unknown arguments.
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	unsigned int num;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'b')
		{
		num = va_arg(args, unsigned int);
		print_binary(num);
			format += 2;
		}
		else
		{
			putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (0);
}
