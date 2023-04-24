#include "main.h"

/**
 * init_params - Entry point
 *
 * @params:Parameters structures.
 * @ap: Arguments ptr
 *
 * Return: (void)
 */


void init_params(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->plus_f = 0;
	params->space_f = 0;
	params->hashtag_f = 0;
	params->zero_f = 0;
	params->minus_f = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->hi_modifier = 0;
	params->le_modifier = 0;
	(void)ap;
}
