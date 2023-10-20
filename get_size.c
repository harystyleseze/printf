#include "main.h"

/**
 * get_size_func - Obtain size of argument cast
 * @format: Format string to print argument
 * @count: argument list_arg
 *
 * Return: value of precision.
 */
int get_size_func(const char *format, int *count)
{
	int curr_i = *count + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*count = curr_i - 1;
	else
		*count = curr_i;

	return (size);
}
