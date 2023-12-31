#include "main.h"

/**
 * char_handler - Handle the %c format specifier.
 * @args_list: va_list of arguments of the char to print.
 * Return: Number of characters printed.
 */
int char_handler(va_list args_list)
{
	char cc = va_arg(args_list, int);

	if (cc == '\0')
	{
		_putchar(cc);
		return (1);
	}

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
		ss = "(null)";

	while (ss[len])
	{
		len++;
	}
	write(1, ss, len);
	return (len);
}




/**
 * binary_from_unsint - Handle the %b format specifier.
 *					turn unsigned int into binary.
 *@args_list: the unsignet int .
 *Return: Number of characters printed.
 */
int binary_from_unsint(va_list args_list)
{
	unsigned int bb = va_arg(args_list, unsigned int);
	int num_bits = 0;
	unsigned int temp = bb;

	while (temp != 0)
	{
		temp /= 2;
		num_bits++;
	}

	if (bb == 0)
	{
		write(1, "0", 1);
		num_bits = 1;
	}
	else
	{
		char buffer[32];  /*Assuming a 32-bit unsigned integer*/
		int i = num_bits - 1;

		while (bb != 0)
		{
			buffer[i] = bb % 2 + '0';
			bb /= 2;
			i--;
		}

		write(1, buffer, num_bits);
	}

	return (num_bits);
}

/**
 * unknown_format_handler - Handle an unknown format specifier.
 * @format: Format specifier string.
 * Return: Number of characters printed.
 */
int unknown_format_handler(const char *format)
{
	write(1, "%", 1); /* Print '%' character */

	if (*format != '\0')  /* Check if the unknown is not null*/
	{
		write(1, format, 1); /* Print the unknown specifier*/
		return (2);  /* Return 2 */
	}
	return (1);
}


