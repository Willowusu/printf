#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char *c)
{
    int len = strlen(c);
    int i = 0, num_bytes = 0;

    char buffer[1024];

    while (i < len)
    {
        num_bytes = len - i < 1024 ? len - i : 1024;
        strncpy(buffer + i, &c[i], num_bytes);
        write(1, buffer, num_bytes);
        i += num_bytes;
    }
}


int main(void)
{
    char *a = "The quick brown fox jumps over the lazy dog The quick brown fox jumps over the lazy dog The quick brown fox jumps over the lazy dog The quick brown fox jumps over the lazy dog The quick brown fox jumps over the lazy dog The quick brown fox jumps over the lazy dog The quick brown fox jumps over the lazy dog\n";

    my_putchar(a);

    return (0);
}