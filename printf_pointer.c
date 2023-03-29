#include <stdio.h>
#include <stdlib.h>

int printf_hex_helper(unsigned long int num);

int printf_hex_helper(unsigned long int num)
{
	long int i;
	long int *array;	/*pointer to array*/
	long int counter = 0;
	unsigned long int temp = num;

	/*count the number of digits needed to represent the hexadecimal number*/
	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;

	/*dynamically allocate an array to store the hexadecimal digits*/
	array = malloc(counter * sizeof(long int));

	/*fill the array with the hexadecimal digits*/
	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}

	/*output the hexadecimal digits in reverse order*/
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;	/*convert to letter representation (A-F)*/
		putchar(array[i] + '0');	/*output the digit*/
	}

	/*free the dynamically allocated array*/
	free(array);

	return (counter);	/*return the number of digits outputted*/
}

int printf_pointer(void* p) /*Added integer argument and void* pointer argument*/
{
    char *s = "(nil)";
    long int a;
    int b;
    int i;

    if (p == NULL)
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            putchar(s[i]);
        }
        return (i);
    }

    a = (unsigned long int)p;
    putchar('0');
    putchar('x');
    b = printf_hex_helper(a);
    putchar('\n');
    return (b + 2);
}

/*int main(void)
{
    int a = 4;
    char buffer[1024] = {'H', 'e', 'l' ,'l', 'o'};
    int arr[12] = {1, 2, 3, 4, 5};
    char *s = "hello";
    printf_pointer(&a);
    printf("%p\n", &a);
    printf_pointer(buffer);
    printf("%p\n", buffer);
    printf_pointer(s);
    printf("%p\n", s);

    return(0);
}*/