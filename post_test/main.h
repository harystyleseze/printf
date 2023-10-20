#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
void write_char(char c, int *count);
void write_string(char *str, int *count);
void write_int(int num, int *count);
int _printf_func(const char *format, ...);

#endif
