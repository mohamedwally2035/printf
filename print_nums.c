#include "main.h"

/**
 * _isdigit - checks if character is digit
 * 
 * @c: character to check
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - the length of a string
 * @s: the string
 *
 * Return: y
 */
int _strlen(char *s)
{
	int y = 0;

	while (*s++)
		y++;
	return (y);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int n = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (n)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i < params->precision)
			*--str = '0';
	if (n)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int x = 0, n, n2, y = _strlen(str);
	char pa_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pa_char = '0';
	n = n2 = (!params->unsign && *str == '-');
	if (n && x < params->width && pa_char == '0' && !params->minus_flag)
		str++;
	else
		n = 0;
	if ((params->plus_flag && !n2) ||
		(!params->plus_flag && params->space_flag && !n2))
		y++;
	if (n && pa_char == '0')
		x += _putchar('-');
	if (params->plus_flag && !n2 && pa_char == '0' && !params->unsign)
		x += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !n2 &&
		!params->unsign && params->zero_flag)
		x += _putchar(' ');
	while (y++ < params->width)
		x += _putchar(pa_char);
	if (n && pa_char == ' ')
		x += _putchar('-');
	if (params->plus_flag && !n2 && pa_char == ' ' && !params->unsign)
		x += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !n2 &&
		!params->unsign && !params->zero_flag)
		x += _putchar(' ');
	x += _puts(str);
	return (x);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int x = 0, n, n2, y = _strlen(str);
	char pa_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pa_char = '0';
	n = n2 = (!params->unsign && *str == '-');
	if (n && x < params->width && pa_char == '0' && !params->minus_flag)
		str++;
	else
		n = 0;

	if (params->plus_flag && !n2 && !params->unsign)
		x += _putchar('+'), y++;
	else if (params->space_flag && !n2 && !params->unsign)
		x += _putchar(' '), y++;
	x += _puts(str);
	while (y++ < params->width)
		x += _putchar(pa_char);

	return (x);
}

