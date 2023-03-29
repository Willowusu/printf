#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - select correct function to print
 * @format: identifier
 * return: the length of the string
 */

int _printf(const char *const format, ...)
{
    char c[1024];
    int arr_size;
    format_specifier conversion_specifier[] = {
        {"%s", printf_string},
        {"%c", printf_char},
        {"%i", printf_int},
        {"%d", printf_int},
        {"%b", printf_binary},
        {"%u", printf_unsigned},
        {"%o", printf_oct},
        {"%x", printf_hexa},
        {"%X", printf_HEX},
        {"%S", printf_custom_conversion},
        {"%R", printf_rot},
        {"%r", printf_reverse},
        {"%p", printf_pointer}
        };

    va_list args;
    int i = 0, len = 0, j = 0, buffer_index = 0;

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format == NULL || (format[i] == '%' && format[i + 1] == '\0'))
            return (0);

        /**
         * Old code has the conversion_specifier array being based on the
         * index "i" instead of the "format specifier".
         * So old code was comparing "format[i]" with
         * "conversion_specifier[j].specifier[0]", which can cue an out of
         * bounds error if the format specifier is longer than 1 character.
         *
         * Code was changed to check if the current index in format is the "%"
         * symbol. If True, the counter is incremented first so as to move the
         * pointer on format to the next char, then a loop runs throught the
         * length of the struct array (this has to be changedto be dynamic) and
         * the format at position i is compared to the specifier at posiiton 1
         * of the conversion specifier struct at position j.
         * If True, the pointer function there is used accordingly.
         *
         * After, the counter, i is incremented again (this was initially a bug),
         * in that, without incrementing it initially, the counter would've still
         * pointed to the char after the "%" and printed it as part of the output.)
         *
         * Everything else just prints characters to the screen till the null char
         * is encountered.
         */
        if (format[i] == '\n')
        {
            if (buffer_index > 0)
            {
                c[buffer_index] = '\0';
                _putchar(c);
                len += buffer_index;
                buffer_index = 0;
            }
            _putchar("\n");
            len++;
            i++;
        }
        else if (format[i] == '%')
        {
            if (buffer_index > 0)
            {
                c[buffer_index] = '\0';
                _putchar(c);
                len += buffer_index;
                buffer_index = 0;
            }

            i++;

            arr_size = sizeof(conversion_specifier) / sizeof(conversion_specifier[0]);
            for (j = 0; j < (arr_size); j++)
            {
                if (format[i] == conversion_specifier[j].specifier[1])
                {
                    conversion_specifier[j].f(args);
                }
            }
            i++;
        }
        else
        {
            c[buffer_index] = format[i];
            buffer_index++;
            len++;
            i++;
        }
    }
    va_end(args);
    return (len);
}
