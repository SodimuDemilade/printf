#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include <stdio.h>
int _printf(const char *format, ...);
int print_format(const char *format, va_list arg);
int c_handle(va_list arg);
int s_handle(va_list arg);
int percent_handle(va_list arg);
int d_handle(va_list arg);
void print_binary(unsigned int num);
int main(void);
#endif
