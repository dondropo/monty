#include "monty.h"


void validate_buffer(char *line, int num_line)
{
	int i = 0;

	instruction_t formlist[] = {
		{"push", NULL},
		{"pall", NULL},
		{"pint", NULL},
		{"pop", NULL},
		{"swap", NULL},
		{"add", NULL},
		{"pop", NULL},
		{NULL, NULL}
	};
		printf("%s", line);
		printf("%d\n", num_line);
	while (formlist[i].opcode != NULL)
	{
		
		if (formlist[i].opcode == line)
		{

			

			//formlist[i].f();
		}
		i++;
	}
}