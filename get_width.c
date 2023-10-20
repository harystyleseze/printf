#include "main.h"

/**
 * get_width_func - obtain width
 * @format: Format string argument
 * @count: argument list_arg to be printed.
 * @list_arg: next argument list_arg.
 *
 * Return: width value.
 */
int get_width_func(const char *format, int *count, va_list list_arg)
{
	int curr_i;
	int width = 0;

	for (curr_i = *count + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (handles_is_digit_func(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list_arg, int);
			break;
		}
		else
			break;
	}

	*count = curr_i - 1;

	return (width);
}
