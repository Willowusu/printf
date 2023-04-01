#include "main.h"

void apply_flags_unsigned(int left_justified, int zero_padded, int field_width, int precision, int precision_specified)
{
    if (precision_specified)
    {
        zero_padded = 0;  // precision takes precedence over zero padding
    }

    if (left_justified)
    {
        printf_left_justify(field_width);
    }
    else if (zero_padded)
    {
        printf_zero_pad(field_width);
    }
    else if (field_width > 0)
    {
        printf_field_width(field_width);
    }
}
