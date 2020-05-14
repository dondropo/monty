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
void pop_element(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp = *head;
	    if (tmp->next != NULL)
	    {
	    	tmp->next->prev = NULL;
	    }
	    *head = (*head)->next;
	    free(tmp);
	}
}

/**
 * nope - Execute the opcode nop
 * @head: pointer to head of the stack
 * @line_num: number of the line
 *
 * Return: none
 */

void nope(stack_t **head, unsigned int line_num)
{
	(void)(head);
	(void)(line_num);
}