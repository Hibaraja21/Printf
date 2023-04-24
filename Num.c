#include "main.h"

/**
 * convert - Entry point.
 *
 * @num: Numbers
 * @base:Base
 * @flags:  Arg flags
 * @params: paramater structure.
 *
 * Return: str
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sig = 0;
	char *pointer;
	unsigned long m = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		m = -num;
		sig = '-';

	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &buffer[49];
	*pointer = '\0';

	do	{
		*--pointer = arr[m % base];
		m /= base;
	} while (m != 0);

	if (sig)
		*--pointer = sig;
	return (pointer);
}

/**
 * print_unsigned -  Arints unsigned int nums
 *
 * @ap:  Argument ptr
 * @params:The parameters structure
 *
 * Return:  Bytes printed.
 */

int print_unsigned(va_list ap, params_t *params)
{
	unsigned long ll;

	if (params->le_modifier)
		ll = (unsigned long)va_arg(ap, unsigned long);
	else if (params->hi_modifier)
		ll = (unsigned short int)va_arg(ap, unsigned int);
	else
		ll = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * print_address - Entry point.
 *
 * @ap:  Argument ptr.
 * @params: The parameters structure
 *
 * Return: Bytes printed.
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int m = va_arg(ap, unsigned long int);
	char *string;

	if (!m)
		return (_puts("(nil)"));

	string = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--string = 'x';
	*--string = '0';
	return (print_number(str, params));
}
