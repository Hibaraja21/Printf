#include "main.h"

/**
 * get_spec - Entry point
 *
 * @str: the format string
 *
 * Return: the number of bytes
 */
int (*get_spec(char *str))(va_list ap, params_t *params)
{
	int index = 0;

	spec_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_b},
		{"o", print_o},
		{"u", print_unsigned},
		{"x", print_h},
		{"X", print_H},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	while (specifiers[index].spec)
	{
		if (*str == specifiers[index].spec[0])
		{
			return (specifiers[index].func);
		}
		index++;
	}
	return (NULL);
}

/**
 * get_print_f - Entry point
 *
 * @str: the format string
 * @appointer: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes
 */
int get_print_f(char *str, va_list appointer, params_t *params)
{
	int (*func)(va_list, params_t *) = get_spec(str);

	if (func)
		return (func(appointer, params));
	return (0);
}

/**
 * get_f - Entry point
 *
 * @str: the format string
 * @params: the parameters struct
 *
 * Return: if valid flag
 */
int get_f(char *str, params_t *params)
{
	int index = 0;

	switch (*str)
	{
		case '+':
			index = params->plus_f = 1;
			break;
		case ' ':
			index = params->space_f = 1;
			break;
		case '#':
			index = params->hashtag_f = 1;
			break;
		case '-':
			index = params->minus_f = 1;
			break;
		case '0':
			index = params->zero_f = 1;
			break;
	}
	return (index);
}

/**
 * get_mod - Entry point
 *
 * @str: the format string
 * @params: the parameters struct
 *
 * Return: valid
 */
int get_mod(char *str, params_t *params)
{
	int index = 0;

	switch (*str)
	{
	case 'h':
		index = params->hi_modifier = 1;
		break;
	case 'l':
		index = params->le_modifier = 1;
		break;
	}
	return (index);
}

/**
 * get_w - Entry point
 *
 * @str: the format string
 * @params: the parameters struct
 * @appointer: the arg
 *
 * Return: pointer
 */
char *get_w(char *str, params_t *params, va_list appointer)
/* should this function use char **s and modify the pointer? */
{
	int digit = 0;

	if (*str == '*')
	{
		digit = va_arg(appointer, int);
		str++;
	}
	else
	{
		while (_isdigit(*str))
			digit = digit * 10 + (*str++ - '0');
	}
	params->width = digit;
	return (str);
}
