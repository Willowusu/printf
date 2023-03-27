#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct format - match the format specifiers for printf
 * @specifier: type
 */

typedef struct format
{
    char *specifier;
    int (*f)();
} format_specifier;

int printf_string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);
int _strlen(char *s);
int printf_int(va_list args);
int _pow_recursion(int x, int y);
int printf_binary(va_list val);
int printf_HEX(va_list val);
int printf_hexa(va_list val);
int printf_oct(va_list val);
int printf_unsigned(va_list args);
int printf_custom_conversion(va_list val);
#endif
