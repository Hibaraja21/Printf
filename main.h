#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>



/**
 * struct Myfmt - Struct op
 *
 * @c: The format.
 * @func: The function associated.
 */
struct Myfmt
{
	char c;
	int (*func)(va_list);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct Myfmt Myfmt_t;

int _printf(const char *format, ...);
int prints_handler(const char *fmt, int *index, va_list args);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char_task0(va_list args);
int print_string_task0(va_list args);
int print_percent_task0(va_list args);

#endif
