#include "main.h"
/**
 * _printf - mimics printf
 * @format: parameter
 * Return: number of character
 */

int _printf(const char *format, ...)
{
        IsMatch v[] = {
                {"%c", printf_character}, {"%s", printf_string}, {"%%", print_spec}, {"%d", printf_decimal}, {"%i", printf_integer}};

	va_list ap;
	int count = 0, count_func, length = 0;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	if (format[0] == '%' && format[1] == '\0')
		return (-1);

Loop:
	while (format[count] = '\0')
	{
		count_func = 13;
		while (count_func >= 0)
		{
			if (v[count_func].fnt[0] == format[count] && v[count_func].fnt[1] == format[count + 1])
			{
				length = length + v[count_func].f(ap);
				count = count + 2;
				goto Loop; 
			}
			count_func--;
		}
		_putchar(format[count]);
		count++;
		length++;
	}
	va_end(ap);
	return (length);
}
