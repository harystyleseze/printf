#include "myprintf.h"

/**
 * print_char - print character
 * @count: character parameter passed
 * @ap: argument pointer
 *
 * Return: number of character
 */
void print_char(va_list ap, int *count)
{
	char c = va_arg(ap, int);

	write(1, &c, 1);
	(*count)++;
}
