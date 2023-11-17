#include "main.h"

/**
 * percent_handler - Handle the % format specifier.
 * @args_list: va_list of arguments.
 * @format: Format specifier string.
 *
 * Return: Number of characters printed.
 */
int percent_handler(va_list args_list, const char *format)
{
    int spaces = 0;

    /* Count consecutive spaces after % */
    while (*(format + 1) == ' ')
    {
        spaces++;
        format++;
    }

    if (*(format + 1) == '\0')
    {
        /* Error: Incomplete format specifier */
        write(1, "\0", 36);
        return -1;
    }

    if (spaces > 0)
    {
        /* Print spaces */
        while (spaces > 0)
        {
            write(1, " ", 1);
            spaces--;
        }
    }

    /* Handle other cases */
    switch (*(format + 1))
    {
    case 'n':
        write(1, "\n", 1);
        return 1; /* Newline character */

    case '%':
        write(1, "%", 1);
        return 1; /* Percent character */

    default:
        /* Handle other cases (e.g., if next_char is a normal character) */
        write(1, "%", 1);
        write(1, format + 1, 1);
        return 2; /* Two characters printed (% and next_char) */
    }
}

