#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Mimic printf function
 * @format: format argument
 * Return: characters accordingly.
 */
int _printf(const char *format, ...)
{
	int count, printed = 0, printed_characters = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list_arg;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list_arg, format);

	for (count = 0; format && format[count] != '\0'; count++)
	{
		if (format[count] != '%')
		{
			buffer[buff_ind++] = format[count];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[count], 1);*/
			printed_characters++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags_func(format, &count);
			width = get_width_func(format, &count, list_arg);
			precision = get_precision_func(format, &count, list_arg);
			size = get_size_func(format, &count);
			++count;
			printed = handle_print_func(format, &count, list_arg, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_characters += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list_arg);

	return (printed_characters);
}

/**
 * print_buffer - Print buffer content if it exist
 * @buffer: Array of characters
 * @buff_ind: Character index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
