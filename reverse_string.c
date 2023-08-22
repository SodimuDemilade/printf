#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

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

	for (len = 0; s[len] != '\0'; len++)
	{
		reverse = malloc(sizeof(char) * len + 1);
		if (reverse == NULL)
			return (NULL);
	}
	_mempcy(reverse, s, len);
	for (head = o; head < len; head++; len--)
	{
		tmp = reverse[len - 1];
		reverse[len - 1] = reverse[head];
		reverse[head] = tmp;
	}
	return (reverse);
}

/**
 * r_handle - main
 * @arg: input
 * Return: count
 */

int r_handle(va_list arg)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = reverse_string(str);
	if (ptr == NULL)
		return (-1);

	for (len = 0; ptr[len] != '\0'; len++)
		putchar(ptr[len]);
	free(ptr);
	return (len);
}
