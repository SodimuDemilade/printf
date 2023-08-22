#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * c_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * Return: count
 */
int c_handle(va_list arg, char *buffer, int *buff_ind)
{
	int i = 0;
	char c = va_arg(arg, int);

	buffer[(*buff_ind)++] = c;
	i++;
	return (i);
}

/**
 * s_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * Return: count
 */
int s_handle(va_list arg, char *buffer, int *buff_ind)
{
	int i = 0;
	char *s = va_arg(arg, char *);


	while (*s != '\0')
	{
		buffer[(*buff_ind)++] = *s;
		i++;
		s++;
	}
	return (i);
}

/**
 * percent_handle - main
 * @buffer: input
 * @buff_ind: input
 * Return: count
 */
int percent_handle(char *buffer, int *buff_ind)
{
	buffer[(*buff_ind)++] = '%';
	return (1);
}

/**
 * d_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * Return: count
 */
int d_handle(va_list arg, char *buffer, int *buff_ind)
{
	int num = va_arg(arg, int);
	int count = 0, num_digits = 0, digits[10], i;

	if (num < 0)
	{
		buffer[(*buff_ind)++] = '-';
		count++;
		num = -num;
	}
	do {
		digits[num_digits] = num % 10;
		num_digits++;
		num /= 10;
	} while (num > 0);
	for (i = num_digits - 1; i >= 0; i--)
	{
		buffer[(*buff_ind)++] = ('0' + digits[i]);
		count++;
	}
	return (count);
}

/**
 * b_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * Return: count
 */
int b_handle(va_list arg, char *buffer, int *buff_ind)
{
	unsigned int num = va_arg(arg, unsigned int);
	int bin_dig[32], num_digits = 0, count = 0, i;

	if (num == 0) 
	{
		buffer[(*buff_ind)++] = '0';
		return (1);
	}
	while (num > 0)
	{
		bin_dig[num_digits] = num % 2;
		num_digits++;
		num /= 2;
	}	
	for (i = num_digits - 1; i >= 0; i--) 
	{
		buffer[(*buff_ind)++] = ('0' + bin_dig[i]);
		count++;
	}
	return (count);
}

/**
 * u_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * Return: count
 */
int u_handle(va_list arg, char *buffer, int *buff_ind)
{
	unsigned int num = va_arg(arg, unsigned int);
	int digits[32], num_digits = 0, count = 0, i;

	do {
		digits[num_digits] = num % 10;	
		num_digits++;
		num /= 10;
	} while (num > 0);
	for (i = num_digits - 1; i >= 0; i--)
	{
		buffer[(*buff_ind)++] = ('0' + digits[i]);
		count++;
	}
	return (count);
}

/**
 * o_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * Return: count
 */
int o_handle(va_list arg, char *buffer, int *buff_ind)
{
	int digits[32], num_digits = 0, count = 0, i;
	unsigned int num = va_arg(arg, unsigned int);

	if (num == 0)
	{
		buffer[(*buff_ind)++] = '0';
		return (count);
	}
	while(num > 0 )
	{
		digits[num_digits] = num % 8;
		num_digits++;
		num /= 8;
	}
	for (i = num_digits - 1; i >= 0; i--)
	{
		buffer[(*buff_ind)++] = ('0' + digits[i]);
		count++;
	}
	return (count);
}
