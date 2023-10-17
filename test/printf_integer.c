#include <unistd.h>
#include <stdarg.h>
#include "myprintf.h"

void print_integer(va_list ap, int *count) {
    int num = va_arg(ap, int);
    int num_len = 0;
    if (num < 0) {
        write(1, "-", 1);
        num = -num;
        num_len++;
    }
    char num_str[12]; // At least 11 characters for a 32-bit integer
    char num_str_rev[12];
    int i = 0;
    do {
        num_str_rev[i] = '0' + num % 10;
        num /= 10;
        i++;
    } while (num > 0);
    for (int j = i - 1; j >= 0; j--) {
        write(1, &num_str_rev[j], 1);
        num_len++;
    }
    (*count) += num_len;
}
