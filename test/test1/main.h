#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct format
{
	char *fnt;
	int (*f)();
} isMatch;

int _printf(const char *format, ...);
int _putchar(char c);
int printf_character(va_list ap);
int printf_string(va_list ap);
int _strlen(char *str);
int _strlen_const(const char *str);
int print_spec(void);
int printf_decimal(va_list ap);
int printf_integer(va_list ap)

#endif
