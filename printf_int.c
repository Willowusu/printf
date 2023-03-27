#include "main.h"

int printf_dec(va_list args)
{
    // check octal and hexadecimal
    // check 0

    int n = va_arg(args, int);
    int num, digit, ind = 1, abenkwan, positive = n;
    n = n / 10;
    num = n;

    if (num == 0)
    {
        _putchar('0');
    }
    else
    {

        if (n < 0)
        {
            positive = n * -1;
            _putchar('-');
        }

        while (positive / 10 != 0)
        {
            ind = ind * 10;
        }
        // abenkwan = num/10;

        while (ind >= 1)
        {
            digit = positive / ind;
            _putchar(digit + '0');
            positive = positive - (digit * ind);
            ind = ind / 10;
        }
    }
}