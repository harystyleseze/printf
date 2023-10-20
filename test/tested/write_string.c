// write_string.c
#include "main.h"
#include <unistd.h>
#include <string.h>
#include "printf_functions.h"

void write_string(char *str, int *count)
{
    int str_len = 0;

    while (str[str_len] != '\0')
    {
        str_len++;
    }
    write(1, str, str_len);
    (*count) += str_len;
}
