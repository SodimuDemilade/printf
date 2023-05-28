#ifndef _PRINTF_H_
#define _PRINTF_H_


#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
int (*check_specifier(const char *format))(va_list)

/** 
 * struct func -struct for a specifier to print
 * @t: character to compare
 * @f: function to handle printing
 */
typedef struct func
{
	char *t;
	int (*f)(va_list);
}func_t;
int print_char(va_list);
int print_cent(va_list);
int print_str(va_list);


#endif /*ifndef _PRINTF_H_*/
