#include <unistd.h>

/**
 * write_string - This is a function that prints to stdout.
 * @str: character to check.
 * @count: integer input.
 *
 * Return: Nothing.
 */

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
