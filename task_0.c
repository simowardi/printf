#include "main.h"

/**
 * char_handler - Handles the %c format specifier.
 * @args_list: va_list of arguments containing the char to print.
 *
 * Return: Number of characters printed.
 */
int char_handler(va_list args_list)
{
	char cc = va_arg(args_list, int);

	/* Check for null character */
	if (cc == '\0')
		cc = '\0';

	write(1, &cc, 1);
	return (1);
}

/**
 * str_handler - Handle the %s format specifier.
 * @args_list: va_list of arguments / strings.
 * Return: Number of characters printed.
 */
int str_handler(va_list args_list)
{
	char *ss = va_arg(args_list, char*);
	int len = 0;

	if (ss == NULL)
	{
		write(1, "(null)", 6);
		return(6);
	}

	else
	{
		while (ss[len])
		{
			len++;
		}
		write(1, ss, len);
		return (len);
	}
}

/**
 * unknown_format_handler - Handles an unknown format specifier.
 * @format: Format specifier string.
 *
 * Return: Number of characters printed.
 */
int unknown_format_handler(const char *format)
{
	/* Print '%' character */
	write(1, "%", 1);

	/* Check if the unknown specifier is not null */
	if (*format != '\0')
	{
		/* Print the unknown specifier */
		write(1, format, 1);
		return (2);  /* Return 2 printed two char: '%', unknown  */
	}

	return (1);  /* Return 1 because we printed one character: '%' */
}

