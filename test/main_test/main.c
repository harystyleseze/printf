#include "my_printf.h"

int main() {
    int len;

    len = my_printf("Let's try to printf a simple sentence.\n");
    my_printf("Character:[%c]\n", 'H');
    my_printf("String:[%s]\n", "I am a string !");
    my_printf("Percent:[%%]\n");
    my_printf("Len:[%d]\n", len);
    my_printf("Length:[%d, %i]\n", len, len);

    return 0;
}
