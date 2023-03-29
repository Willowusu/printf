#include "main.h"

/*This function takes a va_list containing a single unsigned int as an argument,*/
/*converts the unsigned int to a decimal representation, and prints it to stdout.*/
int printf_unsigned(va_list args)
{
    /*Declare necessary variables.*/
    char buffer[1024];
    int buffer_index = 0;
    unsigned int n = va_arg(args, unsigned int);
    unsigned int num = n, digit, exp = 1, exp_digi = n;
    int i = 1;

    if (n == 0)
        _putchar("0");
    else
    {
        /*If the unsigned int is positive, calculate the number of digits in its decimal representation*/
        /*and store the result in the 'i' variable.*/

        while ((exp_digi / 10) != 0)
        {
            exp = exp * 10;
            exp_digi = exp_digi / 10;
        }

        while (exp >= 1)
        {
            /*Calculate the next digit in the decimal representation, print it to stdout,*/
            /*and subtract it from the unsigned int.*/
            digit = num / exp;
            buffer[buffer_index] = digit + '0';
            buffer_index++;

            num = num - (digit * exp);
            exp = exp / 10;
            i++;
        }

        if (buffer_index > 0)
        {
            buffer[buffer_index] = '\0';
            _putchar(buffer);
            buffer_index = 0;
        }
    }

    /*Return the number of digits in the decimal representation.*/
    return (i);
}
