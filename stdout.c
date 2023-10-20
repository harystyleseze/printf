#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_character_func - Prints character to stdout
 * @c: char parameter
 * @buffer: array of buffer to handle print
 * @flags:  specify flags.
 * @width: specify width.
 * @precision: specify precision
 * @size: specify size
 *
 * Return: number of characters.
 */
int handle_write_character_func(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* character is stored at left while paddind is at the right of buffer */
	int count = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[count++] = c;
	buffer[count] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (count = 0; count < width - 1; count++)
			buffer[BUFF_SIZE - count - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - count - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - count - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER TO STDOUT*************************/
/**
 * write_number_function - prints number
 * @is_negative: argument to handles negative number
 * @ind: ind specifier.
 * @buffer: array of buffer to handle print
 * @flags:  specify flags
 * @width: specify width.
 * @precision: specify precision
 * @size: specify size
 *
 * Return: number of characters
 */
int write_number_function(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_number_func(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_number_func - print number from bufffer
 * @ind: buffer index argument
 * @buffer: buffer array
 * @flags: specify flags
 * @width: specify width
 * @prec: specify precision
 * @length: specify length
 * @padd: Pad char
 * @extra_c: additional char
 *
 * Return: number of character
 */
int write_number_func(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int count, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (count = 1; count < width - length + 1; count++)
			buffer[count] = padd;
		buffer[count] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], count - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], count - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], count - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsigned_func - print unsigned number to stdout
 * @is_negative: parameter to handle negative numbers
 * @ind: index of the buffer
 * @buffer: buffer array of chars
 * @flags: specify flags
 * @width: specify width
 * @precision: specify precision
 * @size: specify size
 *
 * Return: number of character.
 */
int write_unsigned_func(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* store number at the right of buffer, then starts at position count */
	int length = BUFF_SIZE - ind - 1, count = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (count = 0; count < width - length; count++)
			buffer[count] = padd;

		buffer[count] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], count));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], count) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * handles_write_pointer_func - print memory address
 * @buffer: buffer array of character
 * @ind: buffer index value
 * @length: handles length
 * @width: specify width
 * @flags: specify flags
 * @padd: padding value
 * @extra_c: additional char
 * @padd_start: padding index
 *
 * Return: number of character
 */
int handles_write_pointer_func(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int count;

	if (width > length)
	{
		for (count = 3; count < width - length + 3; count++)
			buffer[count] = padd;
		buffer[count] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Position additional char to left of the buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], count - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* assign additional char to left of the buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], count - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* assign additional char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], count - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
