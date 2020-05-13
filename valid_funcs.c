#include "monty.h"
/**
 * validate_buffer - validator for the buff's content
 * @line: current line
 * @line_num: number of each line
 * @h: stack_t pointer
 * @file_des: descriptor of the file
 *
 * Return: none
 */

void validate_buffer(char *line, size_t line_num, stack_t **h, FILE *file_des)
{

	char *sepa = " \t\r\n", *opcode = NULL, *datastr = NULL;
	int data = 0;

	opcode = strtok(line, sepa);
	if (opcode)
	{
		if (strcmp("push", opcode) == 0)
		{
			datastr = strtok(NULL, sepa);
			if (!datastr)
			{
				free_dlistint(*h);
				free(line);
				fclose(file_des);
				dprintf(STDERR_FILENO, "L%ld: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
			else
			{
				if (valid_push(datastr))
					data = atoi(datastr);
				else
				{
					free_dlistint(*h);
					free(line);
					fclose(file_des);
					dprintf(STDERR_FILENO, "L%ld: usage: push integer\n", line_num);
					exit(EXIT_FAILURE);
				}
			}
		}
		executer(h, opcode, data, line_num);
	}
}
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
