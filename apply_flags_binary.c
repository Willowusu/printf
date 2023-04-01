#include "main.h"

void apply_flags_binary(int value, int width, int precision, char *output) {
    if (printf_left_justify) {
        printf_left_justify(value, width, precision, output);
    }
    else if (printf_zero_pad) {
        printf_zero_pad(value, width, precision, output);
    }
    else if (printf_field_width) {
        printf_field_width(value, width, precision, output);
    }
}
