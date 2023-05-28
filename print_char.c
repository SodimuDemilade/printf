#include "main.h"
#include <unistd.h>

/**
 * print_char - print a character
 * 
 * @args: variadic parameter
 *
 * return: number of character printed
 */
int print_char(va_list args)
{
	char c = (char)var_arg(args , int);
	int count = 0;
	if(c)
	{
		write(1, &c , 1);
		return (count);
	}
	return (0);
}
