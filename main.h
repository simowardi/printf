#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char *format, ...);

/**
 * FormatSpecifier - Structure to hold format specifier information.
 */
typedef struct FormatSpecifier
{
	char specifier;      /* Format specifier character */
	int (*func)(va_list);  /* Corresponding handling function */
} FormatSpecifier;


typedef int (*print_handler)(va_list);

int handle_f_spec(const char *format, va_list args_list);

int _putchar(char c);

int print_normal_char(const char *c);

int percent_handler(const char *format);

int char_handler(va_list args_list);
int str_handler(va_list args_list);

int int_handler(va_list args_list);

int binary_from_unsint(va_list args_list);
int unknown_format_handler(const char *format);

#endif /* main.h */


