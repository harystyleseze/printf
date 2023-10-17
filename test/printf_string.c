#include "myprintf.h"

/**
 * print_string - print string
 * @count: character parameter
 * @ap: argument pointer
 *
 * Return: number of character
 */

void print_string(va_list ap, int *count)
{
	char *str = va_arg(ap, char*);
	int str_len = 0;

	while (str[str_len] != '\0')
	{
		str_len++;
	}
	write(1, str, str_len);
	(*count) += str_len;
}
