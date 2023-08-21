#include "main.h"
/**
 * _puts - prints a string
 * @str: string to print
 * Return: (void)
 */
int _puts(char *str)
{
	char *c = str;

	while (*str)
		_putchar(*str++);
	return (str - c);
}

/**
 * _putchar - writes the character c to stdout
 * @c:  character to print
 *
 * Return: 1 (success).
 */
int _putchar(int c)
{
	static int z;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || z >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, z);
		z = 0;
	}
	if (c != BUF_FLUSH)
		buf[z++] = c;
	return (1);
}
