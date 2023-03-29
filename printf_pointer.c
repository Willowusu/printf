#include <stdlib.h>
#include "main.h"

int printf_HEX_helper(unsigned int num)
{
    int i;
    int *array;
    int counter = 0;
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

int printf_hexa_helper(unsigned long int num)
{
    long int i;
    long int *array; /*pointer to array*/
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
            array[i] = array[i] + 39; /*convert to letter representation (A-F)*/
        _putchar(array[i] + '0');     /*output the digit*/
    }

    /*free the dynamically allocated array*/
    free(array);

    return (counter); /*return the number of digits outputted*/
}

int printf_pointer(va_list val) /*Added integer argument and void* pointer argument*/
{
    void *p;
    char *s = "(nil)";
    long int a;
    int b;
    int i;
    p = va_arg(val, void *);

    if (p == NULL)
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            _putchar(s[i]);
        }
        return (i);
    }

    a = (unsigned long int)p;
    _putchar('0');
    _putchar('x');
    b = printf_hexa_helper(a);
    _putchar('\n');
    return (b + 2);
}
