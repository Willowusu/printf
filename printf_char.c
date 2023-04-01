#include "main.h"

int printf_char(va_list val)
{
    char c;
    int len = 0;

    c = va_arg(val, int);

    /**
     * Looked at this first conditional again and I still
     * don't get the reason for this. If it's null, why not
     * return 0 then??
     */
    len++;
    _putchar(&c);
    return (len);
}