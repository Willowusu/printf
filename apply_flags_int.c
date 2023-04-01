#include "main.h"

void apply_flags_int(int left_justified, int zero_padded, int field_width, int precision, int precision_specified, int num) {
    char num_str[12]; /* assume 32-bit int, so max 11 digits + 1 null terminator*/
    int num_len = 0;
    if (num == 0) {
        num_str[num_len++] = '0';
    }
    else {
        int is_negative = 0;
        if (num < 0) {
            is_negative = 1;
            num = -num;
        }
        while (num > 0) {
            int digit = num % 10;
            num_str[num_len++] = '0' + digit;
            num /= 10;
        }
        if (is_negative) {
            num_str[num_len++] = '-';
        }
    }

    // apply precision
    if (precision_specified) {
        int num_zeros_to_pad = precision - num_len;
        while (num_zeros_to_pad > 0) {
            num_str[num_len++] = '0';
            num_zeros_to_pad--;
        }
    }

    // apply zero padding
    if (zero_padded && field_width > num_len) {
        int num_zeros_to_pad = field_width - num_len;
        while (num_zeros_to_pad > 0) {
            num_str[num_len++] = '0';
            num_zeros_to_pad--;
        }
    }

    // apply field width
    if (field_width > num_len) {
        int num_spaces_to_pad = field_width - num_len;
        if (left_justified) {
            // pad on the right with spaces
            while (num_spaces_to_pad > 0) {
                num_str[num_len++] = ' ';
                num_spaces_to_pad--;
            }
        }
        else {
            // pad on the left with spaces
            // shift digits to the right to make space for the spaces
            for (int i = num_len - 1; i >= 0; i--) {
                num_str[i + num_spaces_to_pad] = num_str[i];
            }
            // pad on the left with spaces
            while (num_spaces_to_pad > 0) {
                num_str[num_spaces_to_pad - 1] = ' ';
                num_spaces_to_pad--;
            }
            // update the length of the string
            num_len += field_width - num_len;
        }
    }

    // print the number string
    for (int i = 0; i < num_len; i++) {
        _putchar(num_str[i]);
    }
}


