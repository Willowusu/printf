#include <stdlib.h>
#include "main.h"

/*This function takes a va_list containing a single char* string as an argument*/
/*converts any non-printable ASCII characters to a hexadecimal representation*/
/*and prints the resulting string to stdout.*/
int printf_custom_conversion(va_list val)
{
    /*Declare necessary variables.*/
    char *s;
    int cast;
    char buffer[1024];
    int i, len = 0, buffer_index = 0;

    /*Extract the char* string from the va_list argument.*/
    s = va_arg(val, char *);

    /*If the string is null, set it to the string "(null)".*/
    if (s == NULL)
        s = "(null)";

    /*Iterate over each character in the string.*/
    for (i = 0; s[i] != '\0'; i++)
    {
        /*If the character is a non-printable ASCII character, print its hexadecimal representation.*/
        if (s[i] < 32 || s[i] >= 127)
        {
            /*Print the escape characters '\x'.*/
            /*c = '\\';*/
            buffer[buffer_index] = '\\';
            buffer_index++;
            /*_putchar(&c);*/
            buffer[buffer_index] = 'x';
            buffer_index++;
            
            /*_putchar("x");*/
            len = len + 2;

            /*Convert the character to an integer using an intermediate cast operation.*/
            cast = s[i];

            /*If the hexadecimal representation of the character is only one digit, print a leading '0'.*/
            if (cast < 16)
            {
                buffer[buffer_index] = '0';
                buffer_index++;
                /*_putchar("0");*/
                if (buffer_index > 0)
                {
                    buffer[buffer_index] = '\0';
                    _putchar(buffer);
                    buffer_index = 0;
                }
                len++;
            }

            /*Print the hexadecimal representation of the character using the printf_HEX function.*/
            len = len + printf_HEX_helper(cast);
        }
        /*If the character is a printable ASCII character, print it as-is.*/
        else
        {
            /*c = s[i];*/
            buffer[buffer_index] = s[i];
            buffer_index++;
            /*_putchar(&c);*/
            len++;
        }
    }

    if (buffer_index > 0)
    {
        buffer[buffer_index] = '\0';
        _putchar(buffer);
        buffer_index = 0;
    }

    /*Return the number of characters printed to stdout.*/
    return (len);
}
