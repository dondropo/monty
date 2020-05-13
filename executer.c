#include "monty.h"

void reader(char *file)
{
	FILE *file_des;
	char *buffer = NULL;
	size_t bufsize = 0, line_num = 1;
	stack_t *head;

	head = NULL;

	file_des = fopen(file, "r");
	if (!file_des)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &bufsize, file_des) != EOF)
	{
		validate_buffer(buffer, line_num, &head, file_des);
		line_num++;
	}
	free(buffer);
	free_dlistint(head);
	fclose(file_des);
}



void executer(stack_t **h, char *opcode, int data, size_t line_num)
{
	int i = 0, flag = 0;

	instruction_t instruct[] = {
	    {"pall", print_all},
	    {"pint", pint},
	    {"pop", NULL},
	    {"swap", NULL},
	    {"add", NULL},
	    {"pop", NULL},
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
			}
			i++;
		}
	}
	if (flag == 0)
		dprintf(STDERR_FILENO, "L%ld: unknown instruction %s\n", line_num, opcode);
}
