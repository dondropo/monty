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

/**
 * error_handler - Function to handle errors
 * @type_err: number of error
 * @opcode: opcode
 * @line_num: line of error
 * Return: none
 */

void error_handler(int type_err, char *opcode, unsigned int line_num)
{
	switch (type_err)
	{
	case 1:
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_num, opcode);
		clean_memory();
		exit(EXIT_FAILURE);
		break;
	case 2:
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_num);
		clean_memory();
		exit(EXIT_FAILURE);
		break;
	default:
		break;
	}
}

/**
 * clean_memory - memory cleaner
 * Return: none
 */

void clean_memory(void)
{
	if (global.buffer)
		free(global.buffer);
	if (global.file_des)
		fclose(global.file_des);
	if (global.head)
		free_dlistint(global.head);
}
