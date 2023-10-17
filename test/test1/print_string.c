#include "main.h"

/**
 * printf_string - print string
 * @ap: argument pointer
 *
 * Return: number of character
 */
int printf_string(va_list, ap)
{
	char *str;
	int i;
	int str_length;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		str = "(null)";
		str_length = _strlen(str);
		for (i = 0; i < str_length; i++)
			_putchar(str[i]);
		return (length);
	}
	else
	{
		str_length = _strlen(str);
		for (i = 0; i < str_length; i++)
			_putchar(str[i]);
		return (length);
	}
}
