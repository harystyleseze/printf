#include "main.h"

/****************** FUNCTION TO PRINT POINTER ******************/
/**
 * handles_print_pointer_func - print pointer value
 * @par_type: parameter type
 * @buffer: array of buffer
 * @flags:  specify flags
 * @width: specify width
 * @precision: specify precision
 * @size: size specifier
 * Return: number of character
 */
int handles_print_pointer_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long addrs_num;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(par_type, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	addrs_num = (unsigned long)addrs;



	while (addrs_num > 0)
	{
		buffer[ind--] = map_to[addrs_num % 16];
		addrs_num /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[count], BUFF_SIZE - count - 1));*/
	return (handles_write_pointer_func(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* FUNCTION TO HANSLE NON PRINTABLE *************************/
/**
 * handles_print_non_printable_func - print ASCII codes in hexa of non printable chars
 * @par_type: parameter type
 * @buffer: array of buffer to  handle
 * @flags:  specify flags
 * @width: specify width
 * @precision: specify precision
 * @size: specify size
 * Return: number of character
 */
int handles_print_non_printable_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	int count = 0, offset = 0;
	char *str = va_arg(par_type, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[count] != '\0')
	{
		if (handles_is_printable_func(str[count]))
			buffer[count + offset] = str[count];
		else
			offset += append_hexa_code_func(str[count], buffer, count + offset);

		count++;
	}

	buffer[count + offset] = '\0';

	return (write(1, buffer, count + offset));
}

/************************* FUNCTION TO HANDLE REVERSE CHARACTER *************************/
/**
 * print_reverse_func - reverse string.
 * @par_type: parameter type
 * @buffer: Buffer array to handle print
 * @flags:  specify flags
 * @width: obtain width
 * @precision: specify precision
 * @size: specify size
 * Return: number of character
 */

int print_reverse_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int count, count1 = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(par_type, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (count = 0; str[count]; count++)
		;

	for (count = count - 1; count >= 0; count--)
	{
		char z = str[count];

		write(1, &z, 1);
		count1++;
	}
	return (count1);
}
/************************* FUNCTION TO PRINT A STRING IN ROT13 *************************/
/**
 * func_to_print_rot13_string - write string in rot13.
 * @par_type: parameter type
 * @buffer: Buffer array to handle print
 * @flags:  specify flags
 * @width: handle width
 * @precision: specify precision
 * @size: specify size
 * Return: number of character
 */
int func_to_print_rot13_string(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int count, j;
	int nums = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(par_type, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (count = 0; str[count]; count++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[count])
			{
				x = out[j];
				write(1, &x, 1);
				nums++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[count];
			write(1, &x, 1);
			nums++;
		}
	}
	return (nums);
}
