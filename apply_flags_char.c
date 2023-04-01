#include "main.h"

void apply_flags_char(int left_justified, int zero_padded, int field_width)
{
    // Check for left justification
    if (left_justified)
    {
        // Not applicable for single characters
    }

    // Check for zero padding
    if (zero_padded)
    {
        // Not applicable for single characters
    }

    // Check for field width
    if (field_width > 1)
    {
        char c[2];
        c[0] = '%';
        c[1] = '\0';
        printf_field_width(c, 1, field_width, 0);
    }
}
