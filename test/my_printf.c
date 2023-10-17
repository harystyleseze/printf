#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // Added for malloc

// Prototype of the function
int _printf(const char *format, ...);

int main() {

    int len;

    len = _printf("Let's try to printf a simple sentence.\n");
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    _printf("Length:[%d, %i]\n", len, len);
    return 0;
}

int _printf(const char *format, ...) {
    int count = 0;
    va_list ap;
    va_start(ap, format);

    if (format == NULL) // Check for NULL format
        return -1;

    while (*format) {
        if (*format != '%') {
            write(1, format, 1);
            count++;
        } else {
            format++;
            if (*format == '%') {
                write(1, format, 1);
                count++;
            } else if (*format == 'c') {
                char c = va_arg(ap, int);
                write(1, &c, 1);
                count++;
            } else if (*format == 's') {
                char *str = va_arg(ap, char*);
                int str_len = 0;
                while (str[str_len] != '\0') {
                    str_len++;
                }
                write(1, str, str_len);
                count += str_len;
            } else if (*format == 'd' || *format == 'i') {
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
                for (int j = i - 1; j >= 0; j--) { // Corrected loop direction
                    write(1, &num_str_rev[j], 1);
                    num_len++;
                }
                count += num_len;
            }
        }
        format++;
    }

    va_end(ap);
    return count;
}
