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
    void (*apply_flags)(int *, int *, int *, int *, int *);
} format_specifier;


int printf_string(va_list val);
int printf_char(va_list val);
int _putchar(char *c);
int _printf(const char *const format, ...);
int _strlen(const char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_memset(char *s, char b, unsigned int n);
int printf_int(va_list args);
int _pow_recursion(int x, int y);
int printf_binary(va_list val);
int printf_HEX(va_list val);
int printf_hexa(va_list val);
int printf_oct(va_list val);
int printf_unsigned(va_list args);
int printf_custom_conversion(va_list val);
int printf_rot(va_list args);
int printf_reverse(va_list args);
int printf_pointer(va_list val);
int printf_hexa_helper(unsigned long int num);
int printf_HEX_helper(unsigned int num);
char *_strncpy(char *dest, char *src, int n);
void apply_flags_string(int left_justified, int zero_padded, int field_width, int precision, int precision_specified, char *output, const char *str);
void apply_flags_char(int left_justified, int zero_padded, int field_width);
void apply_flags_int(int left_justified, int zero_padded, int field_width, int precision, int precision_specified);
void apply_flags_binary(int value, int width, int precision, char *output);
void apply_flags_unsigned(int left_justified, int zero_padded, int field_width, int precision, int precision_specified);
void apply_flags_oct(int left_justified, int zero_padded, int field_width, int precision, int precision_specified);
void apply_flags_hex(int left_justified, int zero_padded, int field_width, int precision, int precision_specified);
void printf_left_justify(va_list args, int field_width, int precision, int precision_specified);
void printf_zero_pad(va_list args, int field_width, int precision, int precision_specified);
void printf_field_width(va_list args, int field_width, int precision, int precision_specified);

#endif
