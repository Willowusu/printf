#include <stdio.h>
#include "main.h"
#include <limits.h>

/**
 * main - Entry point of program
 *
 * Return: always 0
 */
int main(void)
{
    void *addr;
    unsigned ui = (unsigned int)INT_MAX + 1024;
    char s[] = "Let's try to printf a simple sentence.\n";
    char c = 'H';
    
    addr = (void *)0x7ffe637541f0;

    _printf("%c\n", c);
    _printf("%s\n", s);
    _printf("%S\n", "Best\nSchool");
    _printf("%b\n", 98);

    _printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

    _printf("Positive int. number with [d]: %d\n", 42);
    _printf("Negative int. number with [d]: %d\n", -42);

    _printf("Positive int. number with [i]: %i\n", 42);
    _printf("Negative int. number with [i]: %i\n\n", -42);

    _printf("Positive octal number with [d]: %d\n", 052);
    _printf("Negative octal number with [d]: %d\n", -052);

    _printf("Positive octal number with [i]: %i\n", 052);
    _printf("Negative octal number with [i]: %i\n\n", -052);

    _printf("Positive hex number with [d]: %d\n", 0x2A);
    _printf("Negative hex number with [d]: %d\n", -0x2A);

    _printf("Positive hex number with [i]: %i\n", 0x2A);
    _printf("Negative hex number with [i]: %i\n", -0x2A);

    _printf("Address:[%p]\n", addr);

    return (0);
}
