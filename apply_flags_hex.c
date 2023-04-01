#include "main.h"

void apply_flags_hex(int left_justified, int zero_padded, int field_width, int precision, int precision_specified)
{
    // If precision is specified and zero padding is requested, ignore the zero padding
    if (precision_specified && zero_padded) {
        zero_padded = 0;
    }

    // If left justified, ignore zero padding
    if (left_justified) {
        zero_padded = 0;
    }

    // Update the formatting string based on the flags
    char format[32];
    _printf(format, "%%%s%s%s%sX", left_justified ? "-" : "", zero_padded ? "0" : "", field_width ? "0" : "", precision_specified ? "." : "");

}

