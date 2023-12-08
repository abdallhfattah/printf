#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int itr, current_itr;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_itr = *i + 1; format[current_itr] != '\0'; current_itr++)
	{
		for (itr = 0; FLAGS_CH[itr] != '\0'; itr++)
			if (format[current_itr] == FLAGS_CH[itr])
			{
				flags |= FLAGS_ARR[itr];
				break;
			}

		if (FLAGS_CH[itr] == 0)
			break;
	}

	*i = current_itr - 1;

	return (flags);
}
