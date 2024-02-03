#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
/**
 * _printf - Prints output according to a format.
 * @format: Format string.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += write(1, (char[]){va_arg(args, int)}, 1);
					break;
				case 's':
					count += write(1, va_arg(args, char*), 1);
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, "%", 1);
					break;
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}

