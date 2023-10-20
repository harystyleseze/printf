#include "main.h"
#include <stdio.h>

/**
* _printf - mimic printf
* @format: parameter passed
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
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(argp, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(argp, char *);

				while (*str)
				{
					_putchar(*str);
					count++;
					str++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(argp, int);
				int divisor;

				if (num < 0)
				{
					_putchar('-');
					count++;
					num = -num;
				}

				divisor = 1;
				while (num / divisor > 9)
				{
					divisor *= 10;
				}
				while (divisor > 0)
				{
					_putchar((num / divisor) + '0');
					count++;
					num %= divisor;
					divisor /= 10;
				}
			}
		}
		format++;
	}
	va_end(argp);
	return (count);
}
