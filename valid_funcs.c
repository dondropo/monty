#include "monty.h"

/**
 * valid_push - validator for the push funct
 * @number: number of characters
 *
 * Return: none
 */
int valid_push(char *number)
{
	int i = 0;

	while (number[i])
	{
		if (number[0] == '-')
			i++;
		if (!isdigit(number[i]))
			return (0);
		i++;
	}

	return (1);
}
