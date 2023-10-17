#include "my_printf.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * my_printf - mimic printf
 * @format: parameter passed
 * @argp: argument pointer
 *
 * Return: number of character
 */

int my_printf(const char *format, ...)
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
			write(1, format, 1);
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
				write(1, "%", 1);
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(argp, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(argp, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
				{
					str_len++;
				}

				write(1, str, str_len);
				count += str_len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(argp, int);
				int num_len = 0;

				if (num < 0)
				{
					write(1, "-", 1);
					num = -num;
					num_len++;
				}

				char num_str[12];
				char num_str_rev[12];
				int i = 0;

				do {
					num_str_rev[i] = '0' + num % 10;
					num /= 10;
					i++;
				} while (num > 0);

				for (int j = i - 1; j >= 0; j--)
				{
					write(1, &num_str_rev[j], 1);
					num_len++;
				}
				count += num_len;
			}
		}
		format++;
	}
	va_end(argp);
	return (count);
}
