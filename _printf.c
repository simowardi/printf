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

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0' || *format == '%')
				printed += print_normal_percent(format);

			else
			{
				printed += handle_f_spec(format, args_list);
			}
		}
		else
		{
			printed += print_normal_char(format);
		}
	}
		format++;
	}

	va_end(args_list);

	return (printed);
}

