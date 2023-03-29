#include <stdio.h>
#include <stdlib.h>

/*int printf_HEX(unsigned int val);*/

/*int printf_HEX(unsigned int val)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = val;
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
		putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}*/

/*This function takes a va_list containing a single char* string as an argument*/
/*converts any non-printable ASCII characters to a hexadecimal representation*/
/*and prints the resulting string to stdout.*/
int printf_custom_conversion(char *s)
{
    /*Declare necessary variables.*/
    /*char *s;*/
    int i, len = 0;
    int cast;

    /*Extract the char* string from the va_list argument.*/
    /*s = va_arg(val, char *);*/

    /*If the string is null, set it to the string "(null)".*/
    if (s == NULL)
        s = "(null)";

    /*Iterate over each character in the string.*/
    for (i = 0; s[i] != '\0'; i++)
    {
        /*If the character is a non-printable ASCII character, print its hexadecimal representation.*/
        if (s[i] < 32 || s[i] >= 127)
        {
            /*Print the escape characters '\x'.*/
            putchar('\\');
            putchar('x');
            len = len + 2;

            /*Convert the character to an integer using an intermediate cast operation.*/
            cast = s[i];

            /*If the hexadecimal representation of the character is only one digit, print a leading '0'.*/
            if (cast < 16)
            {
                putchar('0');
                len++;
            }

            /*Print the hexadecimal representation of the character using the printf_HEX function.*/
            /*len = len + printf_HEX(cast);*/
        }
        /*If the character is a printable ASCII character, print it as-is.*/
        else
        {
            putchar(s[i]);
            len++;
        }
    }

    /*Return the number of characters printed to stdout.*/
    return (len);
}

/*int main(void)
{
    char *s = "Best\n\nSchool\n\r\t\a";

    printf_custom_conversion(s);

    return(0);
}*/
