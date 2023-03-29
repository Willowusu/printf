#include "main.h"

/*
The code starts by declaring a variable called array.
 This is an int pointer to the memory location of an array of integers.
 The next line declares a variable called counter that will be used to keep track of how many elements are in the array.
 Then, it starts looping through the code while num / 16 != 0 and increments counter each time it goes around the loop until num has been divided by 16.
 The next part loops through all of the values in the array and divides them by 16 so that they can be converted into hexadecimal numbers (0-9).
 After this, there is another for loop where i = 0; i < counter; i++ which iterates over all of the values in order from 0 to counter - 1.
 If any value in this range is greater than 9 then it will increment its value by 7 and putchar()s out '0'.
 Finally, after freeing up all allocated memory with free(array), return (counter) returns back to main().
 The code prints out the hexadecimal equivalent of a number in v-list.
 The code starts by initializing counter to 0 and num to va_arg(val, unsigned int).
 The loop iterates until num is divisible by 16.
 After that, the loop increments counter and allocates an array with size equal to counter * sizeof(int) .
 Inside the for loop, it iterates through each element of the array and prints out its value as hexadecimal equivalent of 16 bit integer.
 After printing out all elements of the array, it proceeds with incrementing counter and printing last element of the array which is 9 (Hexadecimal digit '9').
 Finally, it frees up allocated
*/
int printf_HEX(va_list val)
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
			array[i] = array[i] + 7;
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}