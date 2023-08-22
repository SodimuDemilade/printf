#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * x_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * Return: count
 */

int x_handle(va_list arg, char *buffer, int *buff_ind)
{
	unsigned int num = va_arg(arg, unsigned int);
	int rem, num_digits = 0, count = 0, i;
	char digits[32];

	if (num == 0)
	{
		buffer[(*buff_ind)++] = '0';
		return (1);
	}
	while (num > 0)
	{
		rem = num % 16;
		if (rem < 10)
		{
			digits[num_digits] = '0' + rem;
			num_digits++;
		}
		else
		{
			digits[num_digits] = 'a' + rem - 10;
			num_digits++;
		}
		num /= 16;
	}
	for (i = num_digits - 1; i >= 0 ; i--)
	{
		buffer[(*buff_ind)++] = digits[i];
		count++;
	}
	return (count);
}

/**
 * X_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * Return: count
 */

int X_handle(va_list arg, char *buffer, int *buff_ind)
{
	unsigned int num = va_arg(arg, unsigned int);
	int rem, num_digits = 0, count = 0, i;
	char digits[32];

	if (num == 0)
	{
		buffer[(*buff_ind)++] = '0';
		return (1);
	}
	while (num > 0)
	{
		rem = num % 16;
		if (rem < 10)
		{
			digits[num_digits] = '0' + rem;
			num_digits++;
		}
		else
		{
			digits[num_digits] = 'A' + rem - 10;
			num_digits++;
		}
		num /= 16;
	}
	for (i = num_digits - 1; i >= 0 ; i--)
	{
		buffer[(*buff_ind)++] = digits[i];
		count++;
	}
	return (count);
}
