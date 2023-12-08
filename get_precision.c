#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int current_itr = *i + 1;
	int precision = -1;

	if (format[current_itr] != '.')
		return (precision);

	precision = 0;

	for (current_itr += 1; format[current_itr] != '\0'; current_itr++)
	{
		if (is_digit(format[current_itr]))
		{
			precision *= 10;
			precision += format[current_itr] - '0';
		}
		else if (format[current_itr] == '*')
		{
			current_itr++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current_itr - 1;

	return (precision);
}
