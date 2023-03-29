#include "main.h"
/*
 * This function takes a va_list of arguments, which should contain a single
 * argument of type char*. It encodes the string using the ROT13 algorithm and
 * prints the encoded string to stdout. It returns the number of characters
 * printed.
 */
int printf_rot(va_list args)
{
    char c;
    int i, j, counter = 0;
    int k = 0;
    char *s = va_arg(args, char *);
    char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

    if (s == NULL)
        s = "(null)";

    for (i = 0; s[i]; i++)
    {
        k = 0;
        for (j = 0; alpha[j] && !k; j++)
        {
            if (s[i] == alpha[j])
            {
                c = beta[j];
                _putchar(&c);
                counter++;
                k = 1;
            }
        }
        if (!k)
        {
            c = s[i];
            _putchar(&c);
            counter++;
        }
    }
    return (counter);
}
