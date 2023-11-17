#include "main.h"

/**
 * reverse_integer - Helper function to reverse an integer.
 * @num: The integer to be reversed.
 */
void reverse_integer(int num)
{
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	if (num >= 10)
	{
		reverse_integer(num / 10);
	}

	_putchar(num % 10 + '0');
}


/**
 * int_handler - Handle the %d and %i format specifiers.
 * @args_list: va_list of arguments type int.
 * Return: Number of characters printed.
 */
int int_handler(va_list args_list)
{
	int dd = va_arg(args_list, int);
	int num_digits = 0;

	if (dd == 0)
	{
		_putchar('0');
		return (1);
	}

	if (dd == -2147483648)
	{
		_putchar('-');
		_putchar('2'); /* Print the first digit of INT_MIN */
		dd = 147483648; /* Set dd to the remaining positive value */
		num_digits += 2; /* Account for '-' and '2' */
	}
	else if (dd < 0)
	{
		_putchar('-');
		dd = -dd;
		num_digits++;
	}

	reverse_integer(dd);

	while (dd >= 10)
	{
		dd /= 10;
		num_digits++;
	}

	return ((num_digits) + 1);
}

