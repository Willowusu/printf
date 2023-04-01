#include "main.h"
#include <stdlib.h>

int printf_HEX_helper(unsigned int num)
{
    int i;
    char buffer[1024];
    int *array;
    int counter = 0, buffer_index = 0;
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
        /*c = array[i] + '0';*/
        buffer[buffer_index] = array[i] + '0';
        buffer_index++;
        /*_putchar(&c);*/
    }

    if (buffer_index > 0)
    {
        buffer[buffer_index] = '\0';
        _putchar(buffer);
        buffer_index = 0;
    }

    free(array);
    return (counter);
}

int printf_hexa_helper(unsigned long int num)
{
    long int i;
    long int *array; /*pointer to array*/
    char buffer[1024];
    long int counter = 0, buffer_index = 0;
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
        /*c = array[i] + '0';*/
        buffer[buffer_index] = array[i] + '0';
        buffer_index++;
        /*_putchar(&c); output the digit*/
    }

    /*free the dynamically allocated array*/
    if (buffer_index > 0)
    {
        buffer[buffer_index] = '\0';
        _putchar(buffer);
        buffer_index = 0;
    }

    free(array);

    return (counter); /*return the number of digits outputted*/
}

int printf_pointer(va_list val) /*Added integer argument and void* pointer argument*/
{
    char buffer[1024];
    void *p;
    char *s = "(nil)";
    long int a;
    int b;
    int i;
    int buffer_index = 0;

    p = va_arg(val, void *);

    printf("Enter here?");
    if (p == NULL)
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            /*c = s[i];*/
            buffer[buffer_index] = s[i];
            buffer_index++;
            /*_putchar(&c);*/
        }

        if (buffer_index > 0)
        {
            buffer[buffer_index] = '\0';
            _putchar(buffer);
            buffer_index = 0;
        }

        return (i);
    }

    a = (unsigned long int)p;

    buffer[buffer_index] = '0';
    buffer_index++;
    buffer[buffer_index] = 'x';
    buffer_index++;

    if (buffer_index > 0)
    {
        buffer[buffer_index] = '\0';
        _putchar(buffer);
        buffer_index = 0;
    }
    /*_putchar("0");*/
    /*_putchar("x");*/
    b = printf_hexa_helper(a);
    return (b + 2);
}
