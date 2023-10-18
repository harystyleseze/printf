#include "main.h"
/**
 * printf_character - print a character
 * @ap: argument pointer
 * Return: Always 1
 */
int printf_character(va_list ap)
{
	char str;

	str = va_arg(ap, int);
	_putchar(str);
	return(1);
}
