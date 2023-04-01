#include "main.h"

void printf_left_justify(va_list args, int field_width, int precision, int precision_specified) {
    char* str = va_arg(args, char*);
    int str_len = _strlen(str);
    int i;
    
    for (i = 0; i < str_len; i++) {
        _putchar(str[i]);
    }
    
    // Add padding on the right
    for (i = 0; i < field_width - str_len; i++) {
        _putchar(' ');
    }
}
