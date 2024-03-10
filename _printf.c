#include "main.h"

/**
 * _printf - Printf function copy,
 * @format: character string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0, str_len;
	char ch, *str;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

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

			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')
			{
				ch = va_arg(args, int);
				write(1, &ch, 1);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				str_len = 0;

				while (str[str_len] != '\0')
					str_len++;


				write(1, str, str_len);
				count += str_len;
			}
		}

		format++;
	}

		va_end(args);

		return (count);
}
