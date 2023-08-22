#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_reversed - a function to reverse a string.
 * @arg: arguments passed
 * Return: output
 */
int print_reversed(va_list arg)
{
	int len;
	char *str;
	char *ptr;

	char *rev_string(char *str);


	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);

	for (len = 0; ptr[len] != '\0'; len++)
		putchar(ptr[len]);
	free(ptr);
	return (len);
}
