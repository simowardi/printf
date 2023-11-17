#include "main.h"

/**
 * print_normal_percent - Print a percent character.
 * @format: Format specifier string.
 * Return: Number of characters printed.
 */
int print_normal_percent(const char *format)
{
	write(1, format, 1); /* Print '%' character */

	return (1);
}
