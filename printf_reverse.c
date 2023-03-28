// Function to print a string in reverse order
// It takes a variable argument list, which contains the string to be printed
int printf_reverse(va_list args)
{
    // Retrieve the string from the variable argument list
    char *s = va_arg(args, char*);
    int i;
    int j = 0;

    // If the string is null, set it to "(null)"
    if (s == NULL)
        s = "(null)";

    // Find the length of the string
    while (s[j] != '\0')
        j++;

    // Print the characters of the string in reverse order
    for (i = j - 1; i >= 0; i--)
        _putchar(s[i]);

    // Return the length of the string
    return (j);
}
