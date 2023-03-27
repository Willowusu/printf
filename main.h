#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

/**
* struct format - match te format specifiers for printf
*@specifier: type
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
int printf_dec(va_list args);


#endif
