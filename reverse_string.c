#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

/**
 * reverse_string - function that reverse string
 *
 * @s: string
 *
 * Return: character pointer.
 */
char *reverse_string(char *s)
{
	int head;
	int len;
	char tmp;
	char *reverse;

	len = strlen(s);
	reverse = malloc(sizeof(char) * (len + 1));
	if (reverse == NULL)
		return (NULL);
	memcpy(reverse, s, len + 1);
	for (head = 0; head < len / 2; head++)
	{
		tmp = reverse[len - head - 1];
		reverse[len - head - 1] = reverse[head];
		reverse[head] = tmp;
	}
	return (reverse);
}

/**
 * r_handle - main
 * @arg: input
 * Return: count
 */

int r_handle(va_list arg, char *buffer, int *buff_ind)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (0);
	ptr = reverse_string(str);
	if (ptr == NULL)
		return (0);

	for (len = 0; ptr[len] != '\0'; len++)
		buffer[(*buff_ind)++] = ptr[len];
	free(ptr);
	return (len);
}
