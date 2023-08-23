#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

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

	if (s == NULL)
		s = "(null)";
	while (*s != '\0')
	{
		buffer[(*buff_ind)++] = *s;
		i++;
		s++;
	}
	buffer[*buff_ind] = '\0';
	return (i);
}


/**
 * d_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * @flags: input
 * @mod: input
 * Return: count
 */
int d_handle(va_list arg, char *buffer, int *buff_ind, int flags, char mod)
{
	int count = 0, num_digits = 0, digits[10], i;
	long num = 0;

	if (mod == 'O')
		num = va_arg(arg, int);
	else if (mod == 'l')
		num = va_arg(arg, long);
	else if (mod == 'h')
		num = (short)va_arg(arg, int);
	if (num < 0)
	{
		buffer[(*buff_ind)++] = '-';
		count++;
		num = -num;
	}
	if (flags & 0x01)
	{
		buffer[(*buff_ind)++] = '+';
		count++;
	}
	else if (flags & 0x02)
	{
		buffer[(*buff_ind)++] = ' ';
		count++;
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
	buffer[*buff_ind] = '\0';
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
	buffer[*buff_ind] = '\0';
	return (count);
}

/**
 * u_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * @mod: input
 * Return: count
 */
int u_handle(va_list arg, char *buffer, int *buff_ind, char mod)
{
	int digits[32], num_digits = 0, count = 0, i;
	unsigned long num = 0;

	if (mod == 'O')
		num = va_arg(arg, unsigned int);
	else if (mod == 'l')
		num = va_arg(arg, unsigned long);
	else if (mod == 'h')
		num = (short)va_arg(arg, unsigned int);
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
	buffer[*buff_ind] = '\0';
	return (count);
}

/**
 * o_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * @flags: input
 * @mod: input
 * Return: count
 */
int o_handle(va_list arg, char *buffer, int *buff_ind, int flags, char mod)
{
	int digits[32], num_digits = 0, count = 0, i;
	unsigned long num = 0;

	if (mod == 'O')
		num = va_arg(arg, unsigned int);
	else if (mod == 'l')
		num = va_arg(arg, unsigned long);
	else if (mod == 'h')
		num = (short)va_arg(arg, unsigned int);
	if (num == 0)
	{
		buffer[(*buff_ind)++] = '0';
		return (count);
	}
	if (flags & 0x04)
	{
		buffer[(*buff_ind)++] = 'O';
		count++;
	}
	while (num > 0)
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
	buffer[*buff_ind] = '\0';
	return (count);
}
