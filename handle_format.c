#include "main.h"

/**
 * handle_f_spec - Handle format specifier and call corresponding function.
 * @format: Format specifier string.
 * @args_list: va_list of arguments.
 * Return: Number of characters printed.
 */
int handle_f_spec(const char *format, va_list args_list)
{
	FormatSpecifier specifiers[] = {
		{'c', char_handler},
		{'s', str_handler},
		{'d', int_handler},
		{'i', int_handler},
		{'b', binary_from_unsint},
		{'\0', NULL}
	};

	for (int i = 0; specifiers[i].specifier != '\0'; i++)
	{
		if (specifiers[i].specifier == *format)
		{
			return (specifiers[i].func(args_list));
		}
	}

	return (unknown_format_handler(format));
}

