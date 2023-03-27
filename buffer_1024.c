//declare buffer 1024
//"the quick brown fox jumps over the lazy dog"

int _putchar(char c)
{
    static char buffer[1024];
    static int i;

    if(c == -1 || i >= 1024)
    {
        write(1, &buffer, i);
        i = 0;
    }
    if(c != -1)
    {
        buffer[i] = c;
        i++;
    }

    return (1);
}

int putting(char *str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
        _putchar(str[i]);
    return (i);
}