#include "main.h"

struct printf_specifier printf_specifiers[] = {
    {'c', (int (*)(va_list))write_char},
    {'s', (int (*)(va_list))write_string},
    {'d', (int (*)(va_list))write_int},
    {'i', (int (*)(va_list))write_int},
};

int printf_specifiers_count = sizeof(printf_specifiers) / sizeof(printf_specifiers[0]);

int _printf(const char *format, ...)
{
    va_list argp;
    va_start(argp, format);

    int count = 0;
    while (*format)
    {
        if (*format != '%')
        {
            write_char(*format, &count);
        }
        else
        {
            format++;
            if (*format == '\0')
            {
                break;
            }
            for (int i = 0; i < printf_specifiers_count; i++)
            {
                if (*format == printf_specifiers[i].spec)
                {
                    count += printf_specifiers[i].handler(argp);
                    break;
                }
            }
        }
        format++;
    }
    va_end(argp);
    return count;
}
