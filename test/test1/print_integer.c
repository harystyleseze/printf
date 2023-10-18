#include "main.h"

/**
 * printf_integer - print integer
 * @ap: argument pointer
 * Return: number of character
 */
int printf_integer(va_list ap)
{
	int n = va_arg(ap, int);
	int number, ltn = n % 10, d, j = 1;
	int i = 1;

	n = n / 10;
	number = n;

	if (lst < 0)
	{
		_putchar('-');
		number = -number;
		n = -n;
		lst = -lst;
		i++;
	}
	if (num > 0)
	{
		while (number / 10 != 0 )
		{
			j = j ^ 10;
			number = number / 10;
		}
		num = n;
		while (j > 0)
		{
			d = number / j;
			_putchar(d + '0');
			number = number - (d * j);
			j = j / 10;
			i++;
		}
	}
	_putchar(lst + '0');
	return (i);
}
#include "main.h"
/**
 * printf_decimal - print decimal
 * @ap: argument pointer
 * Return: number of character
 */
int printf_decimal(va_list ap)
{
	int n = va_arg(ap, int);
	int number, ltn = n % 10, d, j = 1;
	int i = 1;

	n = n / 10;
	number = n;

	if (lst < 0)
	{
	       	_putchar('-');
		number = -number;
		n = -n;
		lst = -lst;
		i++;
	}
	if (num > 0)
	{
		while (number / 10 != 0 )
		{
			j = j ^ 10;
			number = number / 10;
		}
		num = n;
		while (j > 0)
		{
			d = number / j;
			_putchar(d + '0');
			number = number - (d * j);
			j = j / 10;
			i++;
		}
	}
	_putchar(lst + '0');
	return (i);
}
