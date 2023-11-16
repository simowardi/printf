#include "main.h"

/**
 * nnti_handler - Handle the %d and %i format specifiers.
 * @args_list: va_list of arguments type int. %d
 * Return: Number of characters printed.
 */

int nnti_handler(va_list args_list)
{
	int input_integer = va_arg(args_list, int);
	int num_digits = 0;
	int temp = input_integer;
	int index;

	char buffer[12]; /* Assuming a 32-bit integer */

	if (input_integer == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (input_integer < 0)
	{
		write(1, "-", 1);
		temp = -temp;
		num_digits++;
	}

	index = 0;
	while (temp != 0)
	{
		temp /= 10;
		num_digits++;
		index++;
	}

	index--;

	if (input_integer < 0)
		input_integer = -input_integer;

	while (input_integer != 0)
	{
		buffer[index] = input_integer % 10 + '0';
		input_integer /= 10;
		index--;
	}

	write(1, buffer, num_digits);

	return (num_digits);
}

