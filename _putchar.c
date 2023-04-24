#include "main.h"

/**
 * _puts - Entry point
 *
 * Description: 'the program's description'
 *
 * @s: string to print
 *
 * Return: length (Success)
 */

int _puts(char *s)
{
	char *a = s;

	while(*s)
	{
		_putchar(*s++);
	}
	return (s - a);
}

/**
 * _putchar - Entry point
 *
 * Description: 'the program's description'
 *
 * @c: number to check
 *
 * Return: 1 (Success)
 */

int _putchar(int c)
{
	static int index;
	static char buf[BUFF_SIZE];

	if (c == BUFF_F || index >= BUFF_SIZE)
	{
		write(1, buf, index);
		index = 0;
	}
	if (c != BUFF_F)
		buf[index++] = c;
	return (1);
}

