#include "monty.h"

/**
 * rotl - rotl
 * @head: pointer to the top of the list
 * @line_num: line number
 */

void rotl(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head, *new;

	if (temp == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return;
	new->n = (*head)->n;
	new->next = NULL;
	new->prev = temp;
	temp->next = new;
	pop_element(head, line_num);
}

/**
 * rotr - rotr
 * @head: pointer to the top of the list
 * @line_num: line number
 */

void rotr(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head, *origin = *head;

	(void) line_num;
	if (!head)
		return;

	while (temp->next)
		temp = temp->next;

	*head = origin->next;
	(*head)->prev = NULL;
	origin->next = NULL;
	origin->prev = temp;
	temp->next = origin;
}
