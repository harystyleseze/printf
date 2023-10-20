#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Define a function pointer type for the handler functions
typedef int (*printf_handler)(va_list);

// Update the printf_specifiers to use the correct function pointer type
struct printf_specifier printf_specifiers[] = {
    {'c', (printf_handler)write_char},
    {'s', (printf_handler)write_string},
    {'d', (printf_handler)write_int},
    {'i', (printf_handler)write_int},
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

