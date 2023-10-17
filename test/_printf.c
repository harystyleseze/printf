#include <unistd.h>
#include <stdarg.h>
#include "myprintf.h"

/**
 * _printf - handle character, string, and %
 * @format: parameter
 * Return: number of character printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list ap;

	va_start(ap, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;

			if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')
			{
				print_char(ap, &count);
			}
			else if (*format == 's')
			{
				print_string(ap, &count);
			}
			else if (*format == 'd' || *format == 'i')
			{
				print_integer(ap, &count);
			}
		}
		format++;
	}
	va_end(ap);
	return (count);
}
