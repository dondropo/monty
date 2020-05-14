#include "monty.h"

/**
 * reader - command line reader
 * @file: readed file
 *
 * Return: none
 */
void reader(char *file)
{
	size_t bufsize = 0, line_num = 1;

	global.head = NULL;
	global.file_des = NULL;
	global.buffer = NULL;

	global.file_des = fopen(file, "r");
	if (!global.file_des)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (getline(&global.buffer, &bufsize, global.file_des) != EOF)
	{
		validate_buffer(global.buffer, line_num, &global.head);
		line_num++;
	}
	clean_memory();
}

/**
 * validate_buffer - validator for the buff's content
 * @line: current line
 * @line_num: number of each line
 * @h: stack_t pointer
 *
 * Return: none
 */

void validate_buffer(char *line, size_t line_num, stack_t **h)
{

	char *sepa = " \t\r\n", *opcode = NULL, *datastr = NULL;
	int data = 0;

	opcode = strtok(line, sepa);
	if (opcode)
	{

		if (opcode[0] == '#')
			return;

		if (strcmp("push", opcode) == 0)
		{
			datastr = strtok(NULL, sepa);
			if (!datastr)
				error_handler(2, line, line_num);
			else
			{
				if (valid_push(datastr))
					data = atoi(datastr);
				else
					error_handler(2, line, line_num);
			}
		}
		if (executer(h, opcode, data, line_num) == 1)
			error_handler(1, line, line_num);
	}
}

/**
 * executer - execute function
 * @h: stack_t pointer
 * @opcode: opcode interpreter by C
 * @data: stack data
 * @line_num: number of the line
 *
 * Return: 1 if error, 0 if it works
 */

int executer(stack_t **h, char *opcode, int data, size_t line_num)
{
	int i = 0, flag = 0;

	instruction_t instruct[] = {
	    {"pall", print_all}, {"pint", pint},
	    {"pop", pop_element}, {"swap", swap},
	    {"add", add}, {"nop", nope},
	    {"sub", sub}, {"mul", mul},
	    {"pchar", pchar}, {"mod", mod},
		{NULL, NULL}};

	if (strcmp("push", opcode) == 0)
	{
		flag = 1;
		exec_push(h, data);
	}
	else
	{
		while (instruct[i].opcode)
		{
			if (strcmp(opcode, instruct[i].opcode) == 0)
			{
				flag = 1;
				instruct[i].f(h, line_num);
				break;
			}
			i++;
		}
	}
	if (flag == 0)
		return (1);
	return (0);
}
