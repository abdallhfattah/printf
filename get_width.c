
#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int current_itr;
	int width = 0;

	for (current_itr = *i + 1; format[current_itr] != '\0'; current_itr++)
	{
		if (is_digit(format[current_itr]))
		{
			width *= 10;
			width += format[current_itr] - '0';
		}
		else if (format[current_itr] == '*')
		{
			current_itr++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current_itr - 1;

	return (width);
}
