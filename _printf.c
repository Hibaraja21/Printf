#include "main.h"

/**
 * _printf - prints all
 *
 * @format: The fmt str
 *
 * Return: The num of bytes printed
 */
int _printf(const char *format, ...)
{
	int s = 0;
	va_list app;
	char *ap, *start;
	params_t params = PARAMS_INIT;

	va_start(app, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ap = (char *)format; *ap; ap++)
	{
		init_params(&params, app);
		if (*ap != '%')
		{
			s += _putchar(*ap);
			continue;
		}
		start = ap;
		ap++;
		while (get_f(ap, &params))
		{
			ap++; /* next char */
		}
		ap = get_w(ap, &params, app);
		ap = get_precision(p, &params, ap);
		if (get_mod(ap, &params))
			ap++;
		if (!get_spec(ap))
			s += print_from_to(start, ap,
				params.li_modifier || params.he_modifier ? ap - 1 : 0);
		else
			s += get_print_f(ap, app, &params);
	}
	_putchar(BUFF_F);
	va_end(app);
	return (s);
}
