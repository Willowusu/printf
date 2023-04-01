#include "main.h"

int printf_string(va_list val)
{
    char *s;
    int len;

    s = va_arg(val, char *);

    /**
     * Looked at this first conditional again and I still
     * don't get the reason for this. If it's null, why not
     * return 0 then??
     */
    if (s == NULL)
    {
        s = "(null)";
        len = _strlen(s);
        _putchar(s);
        return (len);
    }
    else
    {
        len = _strlen(s);
        _putchar(s);
        return (len);
    }
}
