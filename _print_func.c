#include "main.h"

/**
 * print_char - Entry point (prints character)
 *
 * @ap:  Argument ptr.
 * @params: Parameters structures
 *
 * Return: Number chars printed.
 */
int print_char(va_list ap, params_t *params)
{
	char pa_char = ' ';
	unsigned int pa = 1, su = 0, c = va_arg(ap, int);

	if (params->minus_f)
		su += _putchar(c);
	while (pa++ < params->width)
		su += _putchar(pa_char);
	if (!params->minus_f)
		su += _putchar(c);
	return (su);
}

/**
 * print_int - entry point (prints int)
 *
 * @ap:Argument pointer
 * @params:The params structure
 *
 * Return: Num chars printed
 */


int print_int(va_list ap, params_t *params)
{
	long ll;

	if (params->le_modifier)
		ll = va_arg(ap, long);
	else if (params->hi_modifier)
		ll = (short int)va_arg(ap, int);
	else
		ll = (int)va_arg(ap, int);
	return (print_n(convert(ll, 10, 0, params), params));
}

/**
 * print_string -entry point ( prints string).
 *
 * @ap:  Argument pointer.
 *
 * @params:  The parames struct
 *
 * Return: Num chars printed
 */


int print_string(va_list ap, params_t *params)
{
	char *s = va_arg(ap, char *), pa_char = ' ';
	unsigned int pa = 0, su = 0, a = 0, b;

	(void)params;
	switch ((int)(!s))
		case 1:
			s = NULL_STR;

	b = pa = _strlen(s);
	if (params->precision < pa)
		b = pa = params->precision;

	if (params->minus_f)
	{
		if (params->precision != UINT_MAX)
			for (a = 0; a < pa; a++)
				su += _putchar(*s++);
		else
			su += _puts(s);
	}
	while (b++ < params->width)
		su += _putchar(pa_char);
	if (!params->minus_f)
	{
		if (params->precision != UINT_MAX)
			for (a = 0; a < pa; a++)
				su += _putchar(*s++);
		else
			su += _puts(s);
	}
	return (su);
}

/**
 * print_percent -Entry point( prints string).
 *
 * @ap:  Argument ptr.
 *
 * @params:Params structure
 *
 * Return:Num chars printed
 */

int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - Entry point (custom format specifier)
 *
 * @ap: Argument Pointer
 *
 * @params: The params struct
 *
 * Return: num char printed
 */

int print_S(va_list ap, params_t *params)
{
	char *s = va_arg(ap, char *);
	char *Hex;
	int su = 0;

	if ((int)(!s))
		return (_puts(NULL_STR));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			su += _putchar('\\');
			su += _putchar('x');
			Hex = convert(*s, 16, 0, params);
			if (!Hex[1])
				su += _putchar('0');
			su += _puts(Hex);
		}
		else
		{
			su += _putchar(*s);
		}
	}
	return (su);
}
