#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char *c)
{
	int len = _strlen(c) + 1;
    int i = 0, num_bytes = 0;

    char buffer[1024];

    while (i < len)
    {
        num_bytes = len - i < 1024 ? len - i : 1024;
        _strncpy(buffer + i, &c[i], num_bytes);
        write(1, buffer, num_bytes);
        i += num_bytes;
    }
	return (0);
}
