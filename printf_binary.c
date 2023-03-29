#include "main.h"

/**
 *  The code starts by declaring a variable called flag.
 The value of the variable is 0 initially.
 Next, it declares a variable called cont which will be incremented as the code executes.
 It then defines an unsigned int named num that has been passed to va_arg().
 This function takes in an unsigned int and returns another unsigned int with its bits shifted left by one position from where it was originally defined.
 The next line initializes a for loop that iterates 32 times, each time shifting the bits of num one place to the right so that they are all zero except for their last bit which is 1 (the first bit).
 After this initialization, there's some more code inside of curly braces { } but before we get into what's inside them let's talk about how this works: The first thing you'll notice is that when i = 0; i < 32; i++ {} starts executing at line 3 and continues until line 10 where it stops because p = ((a << (31 - i)) & num); is executed on lines 8-9 and since p >> (31 -i) evaluates to false on line 9 then flag = 1; is executed on lines 11-12 meaning b = p >> (31
 The code is meant to print the binary representation of a number in hexadecimal.
 The code starts by declaring two variables, flag and cont.
 The variable flag will be set to 0 initially, while the variable cont will start at 1.
 Next, the function declares a for loop that iterates through 32 iterations of the loop.
 Each iteration of the loop increments i by 1 until it reaches 32.
 Then, it prints out an ASCII character onscreen based on whether or not there is a '1' in p (the binary representation of num).
 If there is a '1', then b = p >> (31 - i) which would print out 48 as its ASCII equivalent value.
 It also increments cont by 1 before
*/

/*This function takes a va_list containing a single unsigned int as an argument*/
/*converts the unsigned int to a binary representation, and prints it to stdout*/
int printf_binary(va_list val)
{
    /*Declare necessary variables.*/
    int flag = 0;
    int cont = 0;
    int i, a = 1, b;
    unsigned int num = va_arg(val, unsigned int);
    unsigned int p;

    /*Iterate over each bit in the unsigned int, starting from the leftmost bit.*/
    for (i = 0; i < 32; i++)
    {
        /*Shift the number a left by (31-i) bits, then bitwise AND it with the unsigned int.*/
        p = ((a << (31 - i)) & num);
        
        /*If the result of the bitwise AND operation is non-zero, set the 'flag' variable to 1.*/
        if (p >> (31 - i))
            flag = 1;
        
        /*If the 'flag' variable is set, calculate the value of the current bit in the binary representation*/
        /*and print it to stdout. Increment the 'cont' variable to keep track of the number of bits printed.*/
        if (flag)
        {
            b = p >> (31 - i);
            _putchar(b + 48);
            cont++;
        }
    }

    /*If no bits were printed, print a '0' bit to stdout and increment the 'cont' variable.*/
    if (cont == 0)
    {
        cont++;
        _putchar('0');
    }

    /*Return the number of bits printed to stdout.*/
    return (cont);
}
