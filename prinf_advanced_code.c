#include "main.h"
#include <unistd.h>
#include <stdlib.h>

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
    char *num_str;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; // Move to the next character after '%'
            switch (*format)
            {
                case 'c':
                    count += write(1, (char[]){va_arg(args, int)}, 1); // Print a single character
                    break;
                case 's':
                    count += write(1, va_arg(args, char*), 1); // Print a string
                    break;
                case 'd':
                case 'i':
                    num_str = itoa(va_arg(args, int));
                    count += write(1, num_str, strlen(num_str)); // Print an integer
                    free(num_str);
                    break;
                case '%':
                    count += write(1, "%", 1); // Print '%'
                    break;
                default:
                    count += write(1, "%", 1); // If format specifier is not recognized, print '%'
                    break;
            }
        }
        else
        {
            count += write(1, format, 1); // Print regular characters
        }
        format++;
    }

    va_end(args);

    return count;
}

