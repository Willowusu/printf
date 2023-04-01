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
        {"%s", apply_flags_string, printf_string},
        {"%c", apply_flags_char, printf_char},
        {"%i", apply_flags_int, printf_int},
        {"%d", apply_flags_int, printf_int},
        {"%b", apply_flags_binary, printf_binary},
        {"%u", apply_flags_unsigned, printf_unsigned},
        {"%o", apply_flags_oct, printf_oct},
        {"%x", apply_flags_hex, printf_hexa},
        {"%X", apply_flags_hex, printf_HEX},
        {"%S", printf_custom_conversion},
        {"%R", printf_rot},
        {"%r", printf_reverse},
        {"%p", printf_pointer}
        };


    va_list args;
    int i = 0, len = 0, j = 0, buffer_index = 0;

    va_start(args, format);
    int field_width = 0;
    int precision = -1;
    int precision_specified = 0;
    int left_justified = 0;
    int zero_padded = 0;

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

        /**
        * The old code and the modified code both implement a printf-like function in C that can handle different types of format specifiers. However, the modified code includes additional features to handle the - and 0 flag characters, field width, and precision for non-custom conversion specifiers.
        * In the old code, the conversion_specifier array is indexed by the variable i, which represents the index of the current character being processed in the format string. This means that the code checks each element of the array for every character in the format string, which can be inefficient. Additionally, the code only handles single-character format specifiers, so longer format specifiers could potentially cause problems.
        * In the modified code, the conversion_specifier array is looped through for every % character in the format string, which reduces the number of checks and makes the code more efficient. The modified code also uses a struct to store each conversion specifier, which allows for longer format specifiers to be handled correctly.
        * Additionally, the modified code includes new variables to handle the - and 0 flag characters, field width, and precision for non-custom conversion specifiers. These values are extracted from the format string and used to format the output correctly.
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
            _putchar('\n');
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
            // Reset flags
            field_width = 0;
            precision = -1;
            precision_specified = 0;
            left_justified = 0;
            zero_padded = 0;

            // Parse flags
            while (1)
            {
                if (format[i] == '-')
                {
                    left_justified = 1;
                }
                else if (format[i] == '0')
                {
                    zero_padded = 1;
                }
                else
                {
                    break;
                }
                i++;
            }

            // Parse field width
            while (format[i] >= '0' && format[i] <= '9')
            {
                field_width = (field_width * 10) + (format[i] - '0');
                i++;
            }

            // Parse precision
            if (format[i] == '.')
            {
                i++;
                precision_specified = 1;
                precision = 0;
                while (format[i] >= '0' && format[i] <= '9')
                {
                    precision = (precision * 10) + (format[i] - '0');
                    i++;
                }
            }

            arr_size = sizeof(conversion_specifier) / sizeof(conversion_specifier[0]);
            for (j = 0; j < (arr_size); j++)
            {
                if (format[i] == conversion_specifier[j].specifier[1])
                {
                    // Apply formatting flags
                    conversion_specifier[j].apply_flags(left_justified, zero_padded, field_width, precision, precision_specified);
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
        va_end(args);
        return(len);
}

