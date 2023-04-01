#include "main.h"

void printf_field_width(va_list args, int field_width, int precision, int precision_specified) {
    char* str = va_arg(args, char*);
    int str_len = _strlen(str);
    int i;
    
    // Add padding on the left
    for (i = 0; i < field_width - str_len; i++) {
        _putchar(' ');
    }
    
    for (i = 0; i < str_len; i++) {
        _putchar(str[i]);
    }
}