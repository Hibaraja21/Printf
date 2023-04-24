#include "main.h"

/**
 * _isdigit - checks if the char is a digit.
 *
 * @c:  Char to check.
 *
 * Return: 1 if digit, 0 otherwise
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Entry point (returns the length of a string).
 *
 * @s: The str whose len to check.
 *
 * Return:  Int len of str.
 */

int _strlen(char *s)
{
	int a = 0;

	while (*s++)
		a++;
	return (a);
}

/**
 * print_n - Entry point (prints a num with options).
 *
 * @str: the base num as a str.
 *
 * @params: The param structure.
 *
 * Return: chars printed.
 *
 */

int print_n(char *str, params_t *params)
{
	unsigned int a = _strlen(str);
	int n = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (n)
	{
		str++;
		a--;
	}
	if (params->precision != UINT_MAX)
		while (a++ < params->precision)
			*--str = '0';
	if (n)
		*--str = '-';

	if (!params->minus_f)
		return (print_n_r_s(str, params));
	else
		return (print_n_l_s(str, params));
}

/**
 * print_n_r_s - Entry point (prints a number with options).
 *
 * @str: Base num as a str.
 * @params: Parameter structure.
 *
 * Return: chars printed
 */


int print_n_r_s(char *str, params_t *params)
{
	unsigned int m = 0, n, n2, a = _strlen(str);
	char pa_char = ' ';

	if (params->zero_f && !params->minus_f)
		pa_char = '0';
	n = n2 = (!params->unsign && *str == '-');
	if (n && a < params->width && pa_char == '0' && !params->minus_f)
		str++;
	else
		n = 0;
	if ((params->plus_f && !n2) ||
		(!params->plus_f && params->space_f && !n2))
		a++;
	if (n && pa_char == '0')
		m += _putchar('-');
	if (params->plus_f && !n2 && pa_char == '0' && !params->unsign)
		m += _putchar('+');
	else if (!params->plus_f && params->space_f && !n2 &&
		!params->unsign && params->zero_f)
		m += _putchar(' ');
	while (a++ < params->width)
		m += _putchar(pa_char);
	if (n && pa_char == ' ')
		m += _putchar('-');
	if (params->plus_f && !n2 && pa_char == ' ' && !params->unsign)
		m += _putchar('+');
	else if (!params->plus_f && params->space_f && !n2 &&
		!params->unsign && !params->zero_f)
		m += _putchar(' ');
	m += _puts(str);
	return (m);
}

/**
 * print_n_l_s - Entry point (prints a num with options)
 *
 * @str: Base number as a str
 * @params: the parameter structure
 *
 * Return: Char printed
 */

int print_n_l_s(char *str, params_t *params)
{
	unsigned int m = 0, n, n2, a = _strlen(str);
	char pa_char = ' ';

	if (params->zero_f && !params->minus_f)
		pa_char = '0';
	n = n2 = (!params->unsign && *str == '-');
	if (n && a < params->width && pa_char == '0' && !params->minus_f)
		str++;
	else
		n = 0;

	if (params->plus_f && !n2 && !params->unsign)
		m += _putchar('+'), a++;
	else if (params->space_f && !n2 && !params->unsign)
		m += _putchar(' '), a++;
	m += _puts(str);
	while (a++ < params->width)
		m += _putchar(pa_char);
	return (m);
}
