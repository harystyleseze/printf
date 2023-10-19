#include "main.h"

/**
 * _printf_ - mimic printf
 * @format: parameter passed
 *
 * Return: number of character
 */

int _printf_(const char *format, ...)
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
