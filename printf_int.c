#include "main.h"

int printf_int(va_list args)
{

    int n = va_arg(args, int);
    int digit, ind_digi = n;
    /*These are to check for octal or hex so as not alter original variables*/
    int ind = 1, positive = n, position = 0;

    if (n == 0)
    {
        _putchar('0');
    }
    else
    {

        if (n < 0)
        {
            positive = n * -1;
            /**
             * The variable "ind_digi" is for the while loop below
             * We end up having issues with the negative ad positive numbers
             * so this was my solution. If you have a better way of fixing the
             * condition in the while loop, then we can remove this variable.
            */
            ind_digi = positive;
            _putchar('-');
        }

        while ((ind_digi / 10) != 0)
        {
            ind = ind * 10;
            ind_digi /= 10;
        }


        while (ind >= 1)
        {
            digit = positive / ind;

            /**
             * Check if the first digit is 0,
             * the position variable acts as a counter of sorts,
             * now, the only way the function continues into this conditional
             * statement is if and only if the digit and position are 0.
             * Now, for numbers that may have a zero in between, this might be
             * a problem, so the counter, position, is placed outside the if
             * statement and incremented so that the condition always evaluates
             * to False.
             */
            

            _putchar(digit + '0');
            positive = (positive - (digit * ind));
            ind /= 10;
            position++;
        }
    }
    return (position);
}