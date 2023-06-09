#include "main.h"

int printf_reverse(va_list args)
{
    char c;
    char *s = va_arg(args, char *);
    int i;
    int j = 0;

    if (s == NULL)
        s = "(null)";

    while (s[j] != '\0')
        j++;

    for (i = j - 1; i >= 0; i--)
    {
        c = s[i];
        _putchar(&c);
    }
    return (j);
}
