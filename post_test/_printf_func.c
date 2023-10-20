#include "main.h"

/**
 * _printf - mimic printf
 * @format: parameter passed
 *
 * Return: number of character
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list argp;

	va_start(argp, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			write_char(*format, &count);
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == 's')
			{
				char *str = va_arg(argp, char*);

				write_string(str, &count);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(argp, int);

				write_int(num, &count);
			}
		}
		format++;
	}
	va_end(argp);
	return (count);
}
