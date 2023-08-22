#ifndef PRINTF_H
#define PRINTF_H
#define BUFFER_SIZE 1024
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
int _printf(const char *format, ...);
int print_format(const char *format, va_list arg);
int c_handle(va_list arg, char *buffer, int *buff_ind);
int s_handle(va_list arg, char *buffer, int *buff_ind);
int percent_handle(char *buffer, int *buff_ind);
int d_handle(va_list arg, char *buffer, int *buff_ind);
int b_handle(va_list arg, char *buffer, int *buff_ind);
void print_binary(unsigned int b);
<<<<<<< HEAD
int u_handle(va_list arg);
int o_handle(va_list arg);
int x_handle(va_list arg);
int X_handle(va_list arg);
int print_reversed(va_list arg);
char *rev_string(char *str);
=======
int u_handle(va_list arg, char *buffer, int *buff_ind);
int o_handle(va_list arg, char *buffer, int *buff_ind);
int x_handle(va_list arg, char *buffer, int *buff_ind);
int X_handle(va_list arg, char *buffer, int *buff_ind);
int S_handle(va_list arg, char *buffer, int *buff_ind);
int p_handle(va_list arg, char *buffer, int *count);
>>>>>>> 1cc698480f2c2f0c2d827837dd3bb897574e8aaf
#endif
