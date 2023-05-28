#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
        va_list args;
        int count = 0;

        va_start(args, format);
        while (*format != '\0')
        {
        if (*format == '%')
        {
                format++;
                if (*format == 'c')
                {
                        count = select_format(args, &format);
		}
        }
        else
        {
                write(STDOUT_FILENO, format, 1);
                count++;
        }

        format++;
        }
        va_end(args);
        return (count);
}
