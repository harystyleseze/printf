#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include "printf_functions.h"

void write_char(char c, int *count);
void write_string(char *str, int *count);
void write_int(int num, int *count);
void write_string(va_list args);

extern struct printf_specifier printf_specifiers[];
extern int printf_specifiers_count;

#endif
