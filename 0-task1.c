#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function to print output.
 *
 * @format: input.
 *
 * Return: character length.
 *
 */

int _printf(const char *format, ...)
{
	va_list arg;
	char *s;
	int i = 0;

	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			i++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
				putchar(va_arg(arg, int));
			else if (format[i] == 's')
			{
				s = va_arg(arg, char *);
				while (*s != '\0') 
				{
					putchar(*s);
					s++;
				}
			}
			i++;
		}
	}
	va_end(arg);
	return (i);
}

int main(void)
{
	int len;
	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	printf("%d\n", len);
	return (0);
}
