#include "monty.h"

/* void swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int holder;

	if (*head != NULL && (*head)->next != NULL)
	{
		temp = *head;
		hold = temp->next;
		holder = temp->n;
		temp->n = hold->n;
		hold->n = holder;
	}
	else
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
} */

}
/**
 * exec_push - Execute the opcode push
 * @head: pointer to head of the stack
 * @line_num: number of the line
 *
 * Return: none
 */
void pop_element(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(tmp);
}
