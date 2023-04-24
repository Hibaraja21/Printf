#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFF_SIZE 1024
#define BUFF_F -1

#define BUF_SIZE_FIELD 50

#define NULL_STR "(null)"

#define PARAMS_I {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_L	1
#define CONVERT_U	2

/**
 * struct params - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_f: on if plus_flag specified
 * @space_f: on if hashtag_flag specified
 * @hashtag_f: on if _flag specified
 * @zero_f: on if _flag specified
 * @minus_f: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @hi_modifier: on if h_modifier is specified
 * @le_modifier: on if l_modifier is specified
 *
 */
typedef struct params
{
	unsigned int unsign	: 1;

	unsigned int plus_f	: 1;
	unsigned int space_f	: 1;
	unsigned int hashtag_f	: 1;
	unsigned int zero_f	: 1;
	unsigned int minus_f	: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int hi_modifier		: 1;
	unsigned int le_modifier		: 1;
} params_t;

/**
 * struct spec - Struct token
 *
 * @spec: format token
 * @func: The function associated
 */
typedef struct spec
{
	char *spec;
	int (*func)(va_list, params_t *);
} spec_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier.c module */
int (*get_spec(char *s))(va_list ap, params_t *params);
int get_print_f(char *s, va_list ap, params_t *params);
int get_f(char *s, params_t *params);
int get_mod(char *s, params_t *params);
char *get_w(char *s, params_t *params, va_list ap);

/* convert_number.c module */
int print_h(va_list ap, params_t *params);
int print_H(va_list ap, params_t *params);
int print_b(va_list ap, params_t *params);
int print_o(va_list ap, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_n(char *str, params_t *params);
int print_n_r_s(char *str, params_t *params);
int print_n_l_s(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list ap);

/* string_fields.c modoule */
char *get_precision(char *p, params_t *params, va_list ap);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif
