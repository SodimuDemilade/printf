#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_binary - prints binary for an unsigned int.
 * @num: integar to be printed
 * Return: Always 0
 */
void print_binary(unsigned int num)
{
	if (num > 1)
	{
		print_binary(num / 2);
	}
	printf("%d", num % 2);
}
