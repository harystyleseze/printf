// write_char.c
#include "main.h"
#include <unistd.h>
#include "printf_functions.h"

void write_char(char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
}
