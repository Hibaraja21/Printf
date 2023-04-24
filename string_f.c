#include "main.h"

/**
 * get_precision - Entry point
 *
 * @fmt: the format string
 * @params: the parameters struct
 * @appointer: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *fmt, params_t *params, va_list appointer)
{
	int digit = 0;

	if (*fmt != '.')
		return (fmt);
	fmt++;
	if (*fmt == '*')
	{
		digit = va_arg(appointer, int);
		fmt++;
	}
	else
	{
		while (_isdigit(*fmt))
			digit = digit * 10 + (*fmt++ - '0');
	}
	params->precision = digit;
	return (fmt);
}
