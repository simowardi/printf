#include "main.h"


/**
 * intd_handler - Handle the %d and %i format specifiers.
 * @args_list: va_list of arguments type int. %d
 * Return: Number of characters printed.
 */
int intd_handler(va_list args_list)
{
	int dd = va_arg(args_list, int);
	int num_digits = 0;
	int temp = dd;

	if (dd < 0)
	{
		write(1, "-", 1);
		temp = -temp;
		num_digits++;
	}

	while (temp != 0)
	{
		temp /= 10;
		num_digits++;
	}

	if (dd == 0)
	{
		write(1, "0", 1);
		num_digits = 1;
	}
	else
	{
		char buffer[12];  /*Assuming a 32-bit integer*/
		int i = num_digits - 1;

		if (dd < 0)
			dd = -dd;

		while (dd != 0)
		{
			buffer[i] = dd % 10 + '0';
			dd /= 10;
			i--;
		}
		write(1, buffer, num_digits);
	}

	return (num_digits);
}

