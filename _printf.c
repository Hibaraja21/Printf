#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int index, calc_print = 0, counter = 0;

	va_start(args, format);
	for (index = 0; format && format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			write(1, &format[index], 1);
			counter++;
		}
		else
		{
			++index;
			calc_print += prints_handler(format, &index, args);
			if (calc_print == -1)
				return (-1);
			counter += calc_print;
		}

	}
	va_end(args);
	return (counter);
}
