#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


/**
 * print_char_task0 - Entry point
 *
 * Description: 'the program's description'
 *
 * @args: arguments to list
 *
 * Return: count 1 (Success)
 */

int print_char_task0(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string_task0 - Entry point
 *
 * Description: 'the program's description'
 *
 * @args :  arguments to list
 *
 * Return: length (Success)
 */

int print_string_task0(va_list args)
{
	int len = 0;
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		s = "(null)\n";
	}

	while (s[len] != '\0')
		len++;

	return (write(1, s, len));
}

/**
 * print_persent_task0 - Entry point
 *
 * Description: 'the program's description'
 *
 * @args: args to list
 *
 * Return: counter (Success)
 */

int print_persent_task0(va_list args)
{
	(void)(args);
	return (write(1, "%%", 1));
}


/**
 * prints_handler - Entry point
 *
 * Description: 'the program's description'
 *
 * @fmt: string to check
 * @index: index
 * @args: args to list
 *
 * Return: Always 0 (Success)
 */


int prints_handler(const char *fmt, int *index, va_list args)
{
	int i, counter = 0, unknown_len = 0, toprint = -1;

	Myfmt_t myf[] = {
	{'c', print_char_task0},
	{'s', print_string_task0},
	{'%', print_persent_task0},
	{'\0', NULL},
	};
	for (i = 0; myf[i].c != '\0'; i++)
	{
		if (fmt[*index] == myf[i].c)
		{
			counter = (myf[i].func(args));
			return (counter);
		}
	}
	if (myf[i].c == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			unknown_len += write(1, " ", 1);

		unknown_len += write(1, &fmt[*index], 1);
		return (unknown_len);
	}
	return (toprint);
}
