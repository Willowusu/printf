#include "main.h"

/*
The code starts by declaring a variable called array.
 The code then declares the variable counter to be 0, and assigns it the value of va_arg(val, unsigned int).
 Then the code starts looping through while num / 16 != 0.
 It does this for every iteration of the loop until num is divisible by 16 again.
 After that, it increments counter each time so that there are enough values in array for all of them to have been assigned a number from 1-9.
 The next part of the code loops through every element in array and assigns them a number from 1-9 based on their position in array (1st element = 1; 2nd element = 2; 3rd element = 3... 9th element = 9).
 After that, it prints out those numbers using _putchar().
 Finally, after printing out all nine numbers, it frees up memory allocated earlier with free(array)
 The code is used to print a hexadecimal number.
 The first line of the code allocates an array of size 16, as that is the size needed for a single digit in hexadecimal.
 The second line iterates through the array and prints each digit in hexadecimal by calculating it's value with modulo 16.
 The third line calculates how many digits are left after the decimal point, which will be either 0 or 1 depending on whether or not there is a decimal point in the number being printed.
 If there is no decimal point, then we can use %16 to calculate how many digits are left before reaching 9, which would mean that we have reached our target length of 16 digits and therefore need to
 print it out
 */

int printf_hexa(va_list val)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}