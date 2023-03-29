#include "main.h"

/*This function takes a va_list containing a single unsigned int as an argument,*/
/*converts the unsigned int to a decimal representation, and prints it to stdout.*/
int printf_unsigned(va_list args)
{
    /*Declare necessary variables.*/
    unsigned int n = va_arg(args, unsigned int);
    int num, last = n % 10, digit, exp = 1;
    int  i = 1;

    n = n / 10;
    num = n;

    /*Check if the unsigned int is negative, and if so, print a minus sign and*/
    /*convert it to a positive number for the rest of the function.*/
    if (last < 0)
    {
        _putchar('-');
        num = -num;
        n = -n;
        last = -last;
        i++;
    }

    /*If the unsigned int is positive, calculate the number of digits in its decimal representation*/
    /*and store the result in the 'i' variable.*/
    if (num > 0)
    {
        while (num / 10 != 0)
        {
            exp = exp * 10;
            num = num / 10;
        }
        num = n;
        while (exp > 0)
        {
            /*Calculate the next digit in the decimal representation, print it to stdout,*/
            /*and subtract it from the unsigned int.*/
            digit = num / exp;
            _putchar(digit + '0');
            num = num - (digit * exp);
            exp = exp / 10;
            i++;
        }
    }

    /*Print the last digit of the unsigned int to stdout.*/
    _putchar(last + '0');

    /*Return the number of digits in the decimal representation.*/
    return (i);
}
