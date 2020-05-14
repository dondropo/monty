#include "monty.h"

void swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int num;

	if (!*head && (*head)->next != NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		num = temp->n;
		temp->n = temp->next->n;
		temp->next->n = num;
	}
}
