#include "main.h"

/**
 * print_normal_char - Print a normal character or format specifier.
 * @c: Character to be printed.
 * Return: Number of characters printed.
 */
int print_normal_char(const char *c)
{
	if (*c == '%' && *(c + 1) != '\0')
	{
		write(1, c, 1);  /* Print the '%' character */
		return (1);
	}

	write(1, c, 1);  /* Print a regular character */
	return (1);
}


