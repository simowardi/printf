#include "main.h"

/**
 * print_normal_char - Print a normal character.
 * @c: Character to be printed.
 * Return: Number of characters printed.
 */
int print_normal_char(const char *c)
{
	write(1, c, 1);
	return (1);
}
