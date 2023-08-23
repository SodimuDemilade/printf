#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_format - main
 * @arg: input
 * @format: input
 * Return: count
 */
int print_format(const char *format, va_list arg)
{
	int i = 0, len = 0, buff_ind = 0, flags = 0;
	char buffer[BUFFER_SIZE], mod = 'O';

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buff_ind] = (format[i]);
			buff_ind++;
			len++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
			{
				buffer[buff_ind] = '%';
				len++;
				buff_ind++;
			}
			else
			{
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			{
				flags = handle_flags(format, &i);
				i++;
			}
			if (format[i] == 'h' || format[i] == 'l')
			{
				mod = format[i];
				i++;
			}
			switch (format[i])
			{
				case 'c':
					{
					len += c_handle(arg, buffer, &buff_ind);
					break;
					}
				case 's':
					{
					len += s_handle(arg, buffer, &buff_ind);
					break;
					}
				case '%':
					{
					len += percent_handle(buffer, &buff_ind);
					break;
					}
				case 'd':
				case 'i':
					{
					len += d_handle(arg, buffer, &buff_ind, flags, mod);
					break;
					}
				case 'b':
					{
					len += b_handle(arg, buffer, &buff_ind);
					break;
					}
				case 'u':
					{
					len += u_handle(arg, buffer, &buff_ind, mod);
					break;
					}
				case 'o':
					{
					len += o_handle(arg, buffer, &buff_ind, flags, mod);
					break;
					}
				case 'x':
					{
					len += x_handle(arg, buffer, &buff_ind, flags, mod);
					break;
					}
				case 'X':
					{
					len += X_handle(arg, buffer, &buff_ind, flags, mod);
					break;
					}
				case 'S':
					{
					len += S_handle(arg, buffer, &buff_ind);
					break;
					}
				case 'p':
					{
					len += p_handle(arg, buffer, &buff_ind);
					break;
					}
				case 'r':
					{
					len += r_handle(arg, buffer, &buff_ind);
					break;
					}
				default:
					{
						buffer[buff_ind] = '%';
						buff_ind++;
						buffer[buff_ind] = (format[i]);
						buff_ind++;
						len += 2;
					}
			}
			}
		}
		i++;
		if (buff_ind >= BUFFER_SIZE)
		{
			write(1, buffer, buff_ind);
			buff_ind = 0;
		}
	}
	if (buff_ind > 0)
		write(1, buffer, buff_ind);
	return (len);
}
