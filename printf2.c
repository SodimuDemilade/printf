#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    int c, len;
    char ch, *str;
    
    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'c') {
                c = va_arg(args, int);
                ch = (char)c;
                write(STDOUT_FILENO, &ch, 1);
                count++;
            } else if (*format == 's') {
                str = va_arg(args, char *);
                len = 0;
                while (str[len] != '\0') {
                    len++;
                }
                write(STDOUT_FILENO, str, len);
                count += len;
            } else if (*format == '%') {
                write(STDOUT_FILENO, "%", 1);
                count++;
            }
        } else {
            write(STDOUT_FILENO, format, 1);
            count++;
        }
        
        format++;
    }
    
    va_end(args);
    
    return count;
}
