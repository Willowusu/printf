include "main.h"
/*
 * This function takes a va_list of arguments, which should contain a single
 * argument of type char*. It encodes the string using the ROT13 algorithm and
 * prints the encoded string to stdout. It returns the number of characters
 * printed.
 */
int printf_rot(va_list args)
{
    int i, j, counter = 0; // Initialize variables
    int k = 0;
    char *s = va_arg(args, char*); // Get the string argument from va_list
    char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"}; // Define the original alphabet
    char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"}; // Define the ROT13 alphabet

    if (s == NULL) // Check if the string is NULL
        s = "(null)"; // If it is, print "(null)" instead

    for (i = 0; s[i]; i++) // Loop through the characters in the string
    {
        k = 0; // Reset k to 0 for each character in the string
        for (j = 0; alpha[j] && !k; j++) // Loop through the original alphabet until a match is found
        {
            if (s[i] == alpha[j]) // If the character matches
            {
                _putchar(beta[j]); // Print the corresponding ROT13 character
                counter++; // Increment the counter
                k = 1; // Set k to 1 to indicate a match was found
            }
        }
        if (!k) // If no match was found
        {
            _putchar(s[i]); // Print the original character
            counter++; // Increment the counter
        }
    }
    return (counter); // Return the number of characters printed
}
