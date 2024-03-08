#include "main.h"
#include <unistd.h>

/**
 * _printf - Printf function copy,
 * @format: character string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char c, ch, *str;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while ((c = *format++) != '\0')
	{
		if (c != '%')
		{
			_putchar(c);
			count++;
		}
		else
		{
			switch (*format++)
			{
				case 'c':
					ch = va_arg(args, int);
					_putchar(ch);
					count++;
					break;
				case 's':
				{
					str = va_arg(args, char *);

					while (*str)
					{
						_putchar(*str++);
						count++;
					}
				}
				break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(*(format - 1));
					count += 2;
					break;
			}
		}
	}

	va_end(args);

	return (count);
}
