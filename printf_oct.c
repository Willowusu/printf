#include "main.h"

// This function takes a va_list containing a single unsigned int as an argument,
// converts the unsigned int to its octal representation, and prints it to stdout.
int printf_oct(va_list val)
{
    // Declare necessary variables.
    int i;
    int *array;
    int counter = 0;
    unsigned int num = va_arg(val, unsigned int); // Get the unsigned int from the va_list.
    unsigned int temp = num;

    // Determine the number of digits in the octal representation of the unsigned int.
    while (num / 8 != 0)
    {
        num /= 8;
        counter++;
    }
    counter++;

    // Allocate an array to hold the octal digits.
    array = malloc(counter * sizeof(int));

    // Convert the unsigned int to its octal representation and store each digit in the array.
    for (i = 0; i < counter; i++)
    {
        array[i] = temp % 8;
        temp /= 8;
    }

    // Print each digit in the array to stdout in reverse order.
    for (i = counter - 1; i >= 0; i--)
    {
        _putchar(array[i] + '0');
    }

    // Free the memory allocated for the array.
    free(array);

    // Return the number of digits in the octal representation.
    return (counter);
}