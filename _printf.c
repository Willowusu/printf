#include "main.h"
#include <stdarg.h>


/**
 * _printf - select correct function to print
 * @format: identifier 
 * return: the length of the string
*/

int _printf(const char * const format, ...)
{
 format_specifier f[] = {
    {"%s", printf_string}
 };

 va_list args;
 int i = 0, j, len = 0;

 va_start(args, format);
 if(format == NULL || (format[0] =='%' && format[1] == '\0'))
    return (0);

Here: 

    while (format[i] != '\0')
    {
        j = 10;
        while(j >= 0)
        {
            if(f[j].specifier[0] == format[i] && f[j].specifier[1] == format[i + 1])
            {
                len += f[j].f(args);
                i = i + 2;
                goto Here;
            }
            j--;
        }
        _putchar(format[i]);
        len++;
        i++;
    }
    va_end(args);
    return (len);
}
