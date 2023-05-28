#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int select_format(va_list args, const char **format)
{
	int c, len;
        char ch, *str;

		format++;
		if (*format == 'c')
		{
			c = va_arg(args, int);
			ch = (char)c;
			write(STDOUT_FILENO, &ch, 1);
                        count++;
                }
                else if (*format == 's')
                {
                str = va_arg(args, char *);
                len = 0;
                while (str[len] != '\0')
                {
                        len++;
                }
                        write(STDOUT_FILENO, str, len);
                        count += len;
                }
                else if (*format == '%')
                {
                        write(STDOUT_FILENO, "%", 1);
                        count++;
                }
		return (count);
}
