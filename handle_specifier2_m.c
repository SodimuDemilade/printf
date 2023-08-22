#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>

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

/**
 * S_handle - main
 * @arg: input
 * @buffer: input
 * @buff_ind: input
 * Return: count
 */
int S_handle(va_list arg, char *buffer, int *buff_ind)
{
	char *str;
	char temp_buffer[4];
	int count = 0, i;

	str = va_arg(arg, char *);
	while (*str != '\0')
	{
		if (*str >= 32 || *str < 127)
		{
			buffer[(*buff_ind)++] = *str;
			count++;
		}
		else
		{
			sprintf(temp_buffer, "\\x%02X", (unsigned char)*str);
			for (i = 0; i < 4; i++)
			{
				buffer[(*buff_ind)++] = temp_buffer[i];
				count++;
				if (*buff_ind >= BUFFER_SIZE)
				{
					write(1, buffer, *buff_ind);
					*buff_ind = 0;
				}
			}
		}
		str++;
	}
	return (count);
}

/**
 * p_handle - main
 * @arg: input
 * @buffer: innput
 * @buff_ind: input
 * Return: check
 */

int p_handle(va_list arg, char *buffer, int *count)
{
	void *ptr = va_arg(arg, void *);
	unsigned long int num = (unsigned long int)ptr;
	char temp_buffer[64];
	int temp_index = 0, counter = 0, i, digit;

	buffer[(*count)++] = '0';
	buffer[(*count)++] = 'x';
    	if (num == 0)
	{
		buffer[(*count)++] = '0';
		counter++;
		return (counter);
	}
	while (num > 0)
	{
		digit = num % 16;
		if (digit < 10)
		{
			temp_buffer[temp_index++] = '0' + digit;
		}
		else 
		{
			temp_buffer[temp_index++] = 'a' + digit - 10;
		}
		num /= 16;
	}
	for (i = temp_index - 1; i >= 0; i--) {
		buffer[(*count)++] = temp_buffer[i];
		counter++;
	}
	return (counter);
}
