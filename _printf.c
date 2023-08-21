#include "main.h"
/**
 * _printf - prints anything
 * @format: the format string
 * Return: sum
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *c, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && format[2] == '\0')
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		init_params(&params, ap);
		if (*c != '%')
		{
			sum += _putchar(*c);
			continue;
		}
		start = c;
		c++;
		while (get_flag(c, &params)) /* while characters at p is flag characters */
		{
			c++; /* take the next character */
		}
		c = get_width(c, &params, ap);
		c = get_precision(c, &params, ap);
		if (get_modifier(c, &params))
			c++;
		if (!get_specifier(c))
			sum += print_from_to(start, c,
				params.l_modifier || params.h_modifier ? c - 1 : 0);
		else
			sum += get_print_func(c, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
/**
 * print_char - prints character
 * @ap: argument
 * @params: the parameters struct
 * Return: sum
 */
int print_char(va_list ap, params_t *params)
{
	char pa_ch = ' ';
	unsigned int pa = 1, sum = 0, char = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(char);
	while (pad++ < params->width)
		sum += _putchar(pa_ch);
	if (!params->minus_flag)
		sum += _putchar(char);
	return (sum);
}
/**
 * print_percent - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: number chars
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pa_ch = ' ';
	unsigned int pad = 0, sum = 0, y = 0, x;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	x = pad = _strlen(str);
	if (params->precision < pa)
		x = pa = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (y = 0; y < pa; y++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (x++ < params->width)
		sum += _putchar(pa_ch);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (y = 0; y < pa; y++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}
