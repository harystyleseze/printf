#include "main.h"

/**
 * handle_print_func - print value depending on the condition
 * @fmt: format string of argument
 * @list_arg: argument list_arg to be printed
 * @ind: ind value
 * @buffer: array of buffer to handle print
 * @flags: specify flag value
 * @width: specify width.
 * @precision: specify precision
 * @size: Specify size
 *
 * Return: number of character
 */
int handle_print_func(const char *fmt, int *ind, va_list list_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	int count, unknown_length = 0, printed_characters = -1;
	fmt_t fmt_types[] = {
		{'c', print_character_func}, {'s', print_string_func}, {'%', print_percent_func},
		{'i', print_integer_func}, {'d', print_integer_func}, {'b', print_binary_func},
		{'u', print_unsigned_func}, {'o', print_octal_func}, {'x', print_hexa_decimal_func},
		{'X', print_hexa_func_upper}, {'p', handles_print_pointer_func}, {'S', handles_print_non_printable_func},
		{'r', print_reverse_func}, {'R', func_to_print_rot13_string}, {'\0', NULL}
	};
	for (count = 0; fmt_types[count].fmt != '\0'; count++)
		if (fmt[*ind] == fmt_types[count].fmt)
			return (fmt_types[count].fn(list_arg, buffer, flags, width, precision, size));

	if (fmt_types[count].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_length += write(1, &fmt[*ind], 1);
		return (unknown_length);
	}
	return (printed_characters);
}
