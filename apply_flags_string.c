#include "main.h"

void apply_flags_string(int left_justified, int zero_padded, int field_width, int precision, int precision_specified, char *output, const char *str)
{
    int len = _strlen(str);

    if (precision_specified && precision < len)
    {
        len = precision;
    }

    if (field_width > len)
    {
        char padding_char = ' ';
        int padding_length = field_width - len;

        if (zero_padded)
        {
            padding_char = '0';
        }

        // Handle left justification
        if (left_justified)
        {
            _memcpy(output, str, len);
            _memset(output + len, padding_char, padding_length);
        }
        // Handle right justification
        else
        {
            _memset(output, padding_char, padding_length);
            _memcpy(output + padding_length, str, len);
        }
        output[field_width] = '\0';
    }
    else
    {
        _memcpy(output, str, len);
        output[len] = '\0';
    }
}
