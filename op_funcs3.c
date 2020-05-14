#include "monty.h"

/**
 * mul - mul the first two elements in the list
 * @head: pointer to head of the stack
 * @line_num: number of the line
 *
 * Return: none
 */

void mul(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		(*head)->n = ((*head)->n * tmp->n);
		(*head)->prev = NULL;
		free(tmp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%ld: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
}