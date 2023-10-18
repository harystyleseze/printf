#ifndef _PRINTF_H
#define _PRINTF_H

int _printf(const char *format, ...);
void write_char(char c, int *count);
void write_string(char *str, int *count);
void write_int(int num, int *count);

#endif