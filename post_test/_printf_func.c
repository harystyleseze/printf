#include "main.h"

/**
 * _printf_ - mimic printf
 * @format: parameter passed
 *
 * Return: number of character
 */

<<<<<<< HEAD:post_test/_printf_func.c
int _printf(const char *format, ...)
=======
int _printf_(const char *format, ...)
>>>>>>> d9585ca0e825487f039592e7280e3751f0ecdc5d:_printf_func.c
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
<<<<<<< HEAD:post_test/_printf_func.c
			if (*format == 's')
			{
				char *str = va_arg(argp, char*);

				write_string(str, &count);
			}
=======
>>>>>>> d9585ca0e825487f039592e7280e3751f0ecdc5d:_printf_func.c
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
