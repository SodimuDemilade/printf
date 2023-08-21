#include <stdio.h>
#include <stdarg.h>

/**
 * c_handle - main
 * @arg: input
 * Return: count
 */
int c_handle(va_list arg)
{
	int i = 0;
	char c = va_arg(arg, int);

	putchar(c);
	i++;
	return (i);
}

/**
 * s_handle - main
 * @arg: input
 * Return: count
 */
int s_handle(va_list arg)
{
	int i = 0;
	char *s = va_arg(arg, char *);

	while (*s != '\0')
	{
		putchar(*s);
		i++;
		s++;
	}
	return (i);
}

/**
 * percent_handle - main
 * Return: count
 */
int percent_handle(void)
{
	putchar('%');
	return (1);
}

/**
 * d_handle - main
 * @arg: input
 * Return: count
 */
int d_handle(va_list arg)
{
	int num = va_arg(arg, int);
	int count = 0, num_digits = 0, digits[10], i;

	if (num < 0)
	{
		putchar('-');
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
		putchar('0' + digits[i]);
		count++;
	}
	return (count);
}

/**
 * b_handle - main
 * @arg: input
 * Return: count
 */
int b_handle(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	int bin_dig[32], num_digits = 0, count = 0, i;

	if (num == 0) 
	{
		putchar('0');
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
		putchar('0' + bin_dig[i]);
		count++;
	}
	return (count);
}
