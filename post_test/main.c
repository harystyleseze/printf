#include "main.h"

int main() {
    int len;

    len = _printf("Let's try to printf a simple sentence.\n");
    _printf("Character:[%c]\n", 'f');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    _printf("Length:[%d, %i]\n", len, len);

    return 0;
}
