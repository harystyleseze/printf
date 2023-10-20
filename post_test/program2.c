#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned_func - handles unsigned number
 * @par_type: parameter type
 * @buffer: array of buffer to handle print
 * @flags:  specify flags
 * @width: specify width
 * @precision: handles precision
 * @size: specify size
 * Return: number of character
 */
int print_unsigned_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	int count = BUFF_SIZE - 2;
	unsigned long int num = va_arg(par_type, unsigned long int);

	num = convert_unsigned_size_func(num, size);

	if (num == 0)
		buffer[count--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[count--] = (num % 10) + '0';
		num /= 10;
	}

	count++;

	return (write_unsigned_func(0, count, buffer, flags, width, precision, size));
}

/************* FUNCTION TO PRINT UNSIGNED NUMBER IN OCTAL ****************/
/**
 * print_octal_func - handles unsigned number in octal notation
 * @par_type: parameter type
 * @buffer: array of buffer to handle print
 * @flags:  handles flags
 * @width: handles width
 * @precision: specify precision
 * @size: specify size
 * Return: number of character
 */
int print_octal_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{

	int count = BUFF_SIZE - 2;
	unsigned long int num = va_arg(par_type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_unsigned_size_func(num, size);

	if (num == 0)
		buffer[count--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[count--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[count--] = '0';

	count++;

	return (write_unsigned_func(0, count, buffer, flags, width, precision, size));
}

/************** FUNCTION TO PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexa_decimal_func - print unsigned number in hexadecimal notation
 * @par_type: parameter type
 * @buffer: array of buffer to handle print
 * @flags:  handles flags
 * @width: handles width
 * @precision: specify precision
 * @size: specify size
 * Return: number of character
 */
int print_hexa_decimal_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa_func(par_type, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* FUNCTION TO PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_func_upper - print unsigned number in upper hexadecimal notation
 * @par_type: parameter type
 * @buffer: array of buffer to handle print
 * @flags:  handles flags
 * @width: handles width
 * @precision: specify precision
 * @size: specify size
 * Return: number of character
 */
int print_hexa_func_upper(va_list par_type, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa_func(par_type, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** FUNCTION TO PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa_func - print hexadecimal number in lower or upper
 * @par_type: parameter type
 * @map_to: Array to map the number to buffer
 * @buffer: array of buffer
 * @flags:  handles flags
 * @flag_ch: handles flags
 * @width: handles width
 * @precision: specify precision
 * @size: specify size
 *
 * Return: number of character
 */
int print_hexa_func(va_list par_type, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int count = BUFF_SIZE - 2;
	unsigned long int num = va_arg(par_type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_unsigned_size_func(num, size);

	if (num == 0)
		buffer[count--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[count--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[count--] = flag_ch;
		buffer[count--] = '0';
	}

	count++;

	return (write_unsigned_func(0, count, buffer, flags, width, precision, size));
}
