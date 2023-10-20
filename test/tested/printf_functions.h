#ifndef PRINTF_FUNCTIONS_H
#define PRINTF_FUNCTIONS_H

#include <stdarg.h>

struct printf_specifier {
    char spec;
    int (*handler)(va_list args);
};

int _printf(const char *format, ...);

#endif
