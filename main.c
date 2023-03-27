#include <stdio.h>
#include "main.h"

/**
 * main - Entry point of program
 *
 * Return: always 0
 */
int main(void)
{

    char c[] = "Let's try to printf a simple sentence.\n";
    _printf("%s\n", c);
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

    return (0);
}
