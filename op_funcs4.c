#include "monty.h"

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