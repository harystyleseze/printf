#include "main.h"

/**
 * handles_is_printable_func - check if character is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int handles_is_printable_func(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code_func - Append ASCII value of hexadecimal code to buffer
 * @buffer: buffer array of char
 * @count: buffer index
 * @ascii_code: ASSCI CODE.
 *
 * Return: 3 always
 */
int append_hexa_code_func(char ascii_code, char buffer[], int count)
{
	char map_to[] = "0123456789ABCDEF";
	/* Hexa fmt code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[count++] = '\\';
	buffer[count++] = 'x';

	buffer[count++] = map_to[ascii_code / 16];
	buffer[count] = map_to[ascii_code % 16];

	return (3);
}

/**
 * handles_is_digit_func - Evaluate character if digit
 * @c: Char parameter
 *
 * Return: 1 if c is a digit, 0 if otherwise
 */
int handles_is_digit_func(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_number_size_func - convert number to certain size
 * @num: number parameter passed
 * @size: size
 *
 * Return: number
 */
long int convert_number_size_func(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_unsigned_size_func - convert unsigned value
 * @num: number parameter passed
 * @size: size of number
 *
 * Return: number
 */
long int convert_unsigned_size_func(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
