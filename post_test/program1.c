#include "main.h"

/************************* PRINT CHARACTER FUNCTION *************************/

/**
 * print_character_func - print character
 * @par_type: parameter type
 * @buffer: Array of buffer to handle
 * @flags:  specify flags
 * @width: specify width
 * @precision: specify precision
 * @size: specify size
 * Return: number of character
 */
int print_character_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(par_type, int);

	return (handle_write_character_func(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING FUNCTION*************************/
/**
 * print_string_func - write string value
 * @par_type: parameter
 * @buffer: array of buffer
 * @flags:  specify flags
 * @width: specify width.
 * @precision: specify precision
 * @size: specify size
 * Return: number of character
 */
int print_string_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, count;
	char *str = va_arg(par_type, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (count = width - length; count > 0; count--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (count = width - length; count > 0; count--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN FUNCTION*************************/
/**
 * print_percent_func - print percent sign to stdout
 * @par_type: parameter passed
 * @buffer: array of buffer
 * @flags:  specify flags
 * @width: specify width.
 * @precision: specify precision
 * @size: specify size
 * Return: number of character
 */
int print_percent_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(par_type);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT FUNCTION *************************/
/**
 * print_integer_func - print integer function
 * @par_type: parameter type
 * @buffer: array of buffer
 * @flags:  specify flags
 * @width: specify width.
 * @precision: specify precision
 * @size: specify size
 * Return: number of character
 */
int print_integer_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	int count = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(par_type, long int);
	unsigned long int num;

	n = convert_number_size_func(n, size);

	if (n == 0)
		buffer[count--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[count--] = (num % 10) + '0';
		num /= 10;
	}

	count++;

	return (write_number_function(is_negative, count, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY FUNCTION *************************/
/**
 * print_binary_func - returns unsigned number
 * @par_type: parameter type
 * @buffer: array of buffer
 * @flags:  handle flags
 * @width: handle width.
 * @precision: specify precision
 * @size: specify size
 * Return: number of character
 */
int print_binary_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, count, sum;
	unsigned int a[32];
	int count1;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(par_type, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (count = 1; count < 32; count++)
	{
		m /= 2;
		a[count] = (n / m) % 2;
	}
	for (count = 0, sum = 0, count1 = 0; count < 32; count++)
	{
		sum += a[count];
		if (sum || count == 31)
		{
			char z = '0' + a[count];

			write(1, &z, 1);
			count1++;
		}
	}
	return (count1);
}
