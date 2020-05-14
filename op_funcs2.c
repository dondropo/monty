#include "monty.h"

/**
 * swap - Swaps the first two elements in the list
 * @head: pointer to head of the stack
 * @line_num: number of the line
 *
 * Return: none
 */

void swap(stack_t **head, unsigned int line_num)
{
	stack_t *tmp, *current;
	int num;

	if (*head != NULL && (*head)->next != NULL)
	{
		tmp = *head;
		current = tmp->next;
		num = tmp->n;
		tmp->n = current->n;
		current->n = num;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop_element - Pops the first element in the stack
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
	else
	{
		tmp = *head;
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
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
