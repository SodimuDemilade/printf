#include <stdio.h>
#include <stdarg.h>
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
	buffer[*buff_ind] = '\0';
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
	buffer[*buff_ind] = '\0';
	return (1);
}
