#include <unistd.h>

/**
 * write_char - This is a function to print to stdout.
 * @c: character to check.
 * @count: integer input.
 *
 * Return: Nothing.
 */

void write_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}
