#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len, len2, len3, len4;
    unsigned int ui;
    void *addr;

    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("Length:[%i]\n", len);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
     _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("%b\n", 98);
     _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
     _printf("%S\n", "Best\nSchool");
     _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    _printf("Reverse:[%r]\n", "string");
    _printf("%+d\n", 45);
    _printf("%ld\n", 567890);
    _printf("%hd\n", 3409);
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
_printf("%o\n", 0);
len3 = _printf("%+d\n", 1024);
len4 = printf("%+d\n", 1024);
printf("%d\n", len3);
printf("%d\n", len4);

    return (0);
}
