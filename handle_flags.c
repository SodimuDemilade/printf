#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_flags - main
 * @input: input
 * Return: output
 */

int handle_flags(const char *input, int *i)
{
	int flags = 0;

	if (input[*i]  == '+')
	{
		flags |= 0x01;
	}
	else if (input[*i] == ' ')
	{
		flags |= 0x02;
	}
	else if (input[*i] == '#')
	{
		flags |= 0x04;
	}
	return (flags);
}
