#include "main.h"

/**
 * get_flags - this calculates the active flags
 * @format: the formatted string where we print the arguments
 * @i: this takes a parameter.
 *
 * Return: the flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int y, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (y = 0; FLAGS_CH[y] != '\0'; y++)
			if (format[curr_i] == FLAGS_CH[y])
			{
				flags |= FLAGS_ARR[y];
				break;
			}

		if (FLAGS_CH[y] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}