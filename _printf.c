#include "main.h"

/**
 * _printf - printf main function.
 * @format: String format / placeholder /
 * special characters and format specifiers.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int printed = 0;

	va_list args_list;

	if (format == NULL)
		return (-1);

	va_start(args_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			printed += print_normal_char(format);
		}
		else
		{
			format++;
			if (*format == '\0' || *format == '\n')
				return (1);

			if (*format == '%')
				printed += percent_handler(format);

			else
				printed += handle_f_spec(format, args_list);

		}
		format++;
	}
	va_end(args_list);

	return (printed);
}


