#include "main.h"

/**
 * get_precision_func - Obtain precision
 * @format: Format parameter passed as arguments
 * @count: arguments that needs to be printed.
 * @list_arg: the argument lists.
 *
 * Return: value of precision.
 */
int get_precision_func(const char *format, int *count, va_list list_arg)
{
	int curr_i = *count + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (handles_is_digit_func(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list_arg, int);
			break;
		}
		else
			break;
	}

	*count = curr_i - 1;

	return (precision);
}
