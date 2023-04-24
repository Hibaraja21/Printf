#include "main.h"

/**
 * print_h - Entry point
 *
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes
 */
int print_h(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *s;

	if (params->le_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->hi_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	s = convert(l, 16, CONVERT_U | CONVERT_L, params);
	if (params->hashtag_f && l)
	{
		*--s = 'x';
		*--s = '0';
	}
	params->unsign = 1;
	return (c += print_n(s, params));
}

/**
 * print_H - prints unsigned hex numbers in uppercase
 *
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes
 */
int print_H(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *s;

	if (params->le_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->hi_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	s = convert(l, 16, CONVERT_U, params);
	if (params->hashtag_f && l)
	{
		*--s = 'X';
		*--s = '0';
	}
	params->unsign = 1;
	return (c += print_n(s, params));
}
/**
 * print_b - Entry point
 *
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes
 */
int print_b(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *s = convert(n, 2, CONVERT_U, params);
	int c = 0;

	if (params->hashtag_f && n)
		*--s = '0';
	params->unsign = 1;
	return (c += print_n(s, params));
}

/**
 * print_o - Entry point
 *
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes
 */
int print_o(va_list ap, params_t *params)
{
	unsigned long l;
	char *s;
	int c = 0;

	if (params->le_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->hi_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	s = convert(l, 8, CONVERT_U, params);

	if (params->hashtag_f && l)
		*--s = '0';
	params->unsign = 1;
	return (c += print_n(s, params));
}
