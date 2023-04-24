#include "main.h"

/**
 * print_from_to - Entry point
 *
 * @s: starting address
 * @stp: stopping address
 * @ex: except address
 *
 * Return: number bytes
 */
int print_from_to(char *s, char *stp, char *ex)
{
	int sum = 0;

	while (s <= stp)
	{
		if (s != ex)
			sum += _putchar(*s);
		s++;
	}
	return (sum);
}

/**
 * print_rev - Entry point
 *
 * @appointer: string
 * @params: the parameters struct
 *
 * Return: number
 */
int print_rev(va_list appointer, params_t *params)
{
	int length, sum = 0;
	char *s = va_arg(appointer, char *);
	(void)params;

	switch ((int)(!*s))
			case 1:
				*s = NULL_STR;
	if (s)
	{
		for (length = 0; *s; s++)
			length++;
		s--;
		for (; length > 0; length--, s--)
			sum += _putchar(*s);
	}
	return (sum);
}

/**
 * print_rot13 - Entry point
 *
 * @appointer: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list appointer, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *fmt = va_arg(appointer, char *);
	(void)params;

	i = 0;
	index = 0;
	while (fmt[i])
	{
		if ((fmt[i] >= 'A' && fmt[i] <= 'Z')
		    || (fmt[i] >= 'a' && fmt[i] <= 'z'))
		{
			index = fmt[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(fmt[i]);
		i++;
	}
	return (count);
}
