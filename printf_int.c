#include "main.h"

int printf_int(va_list args)
{

    int n = va_arg(args, int);
    int digit, base, ind_digi = n, base10num = 0;
    /*These are to check for octal or hex so as not alter original variables*/
    int pos_ch, digit_ch, ind_ch, hex_num;
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

        ind_ch = ind; /*Set the indice checker to the original value*/

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
            if (digit == 0 && position == 0)
            {
                /**
                 * Now check second digit,
                 * if a number, then it's octal,
                 * else id its 'x' or 'X',
                 * it's hex. Work accordingly.
                 */

                /**
                 * I really didn't want to break code but I feel these
                 * two variables can go. So you can do something.
                 */
                pos_ch = positive;
                digit_ch = digit;

                pos_ch -= (digit_ch * ind_ch);
                ind_ch /= 10;
                digit_ch = pos_ch / ind_ch;

                if (digit_ch >= 0 && digit_ch <= 9)
                    base = 8;
                else if (digit_ch == 'x' || digit_ch == 'X')
                    base = 16;

                /*Convert base 8 number to base 10 number*/
                if (base == 8)
                {
                    while (positive != 0)
                    {
                        digit = positive % base;
                        base10num += positive * _pow_recursion(8, position);
                        _putchar(base10num + '0');
                        position++;
                        positive /= 10;
                    }
                }
                else if (base == 16)
                {
                    /**
                     * For hex numbers generally, the convention used is
                     * "0x#"", where "0x" is the convention used to distinguish
                     * hex from any other number type. Hence to covert them,
                     * we'll need to access the 2th element in the numbers given
                     * to convert.
                     *
                     * Say for example, 0x2A, we need to start working from the numbers
                     * after the "x" to convert properly.
                     * We'll work accordingly.
                     */

                    /**
                     * We'll use the variables from the checker conditional since
                     * they start at the positions we're interested in
                     */
                    while (ind_ch >= 1)
                    {
                        pos_ch -= (digit_ch * ind_ch);
                        ind_ch /= 10;
                        digit_ch = pos_ch / ind_ch;

                        if (digit_ch >= 0 && digit_ch <= 9)
                            hex_num = digit_ch - 0;
                        else if (digit_ch >= 'a' && digit_ch <= 'f')
                            hex_num = (digit_ch - 'a') + 10;
                        else if (digit_ch >= 'A' && digit_ch <= 'F')
                            hex_num = (digit_ch - 'A') + 10;

                        base10num += hex_num * _pow_recursion(16, position);
                        _putchar(base10num + '0');
                        position++;
                    }
                }
                break;
            }

            _putchar(digit + '0');
            positive = (positive - (digit * ind));
            ind /= 10;
            position++;
        }
    }
    return (position);
}