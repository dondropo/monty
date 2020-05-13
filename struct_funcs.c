#include "monty.h"

/**
 * print_dlistint - Function to print a double list
 * @h: head of the simple list
 * Return: Size of the list
 */

size_t print_dlistint(const stack_t *h)
{
	size_t counter = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		counter++;
	}
	return (counter);

	return (0);
}

/**
 * add_dnodeint_end - function that adds a node at the end
 * @head: head of the list
 * @n: number of the instance
 * Return: new list
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *temp;

	temp = *head;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (!*head)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		while (temp->next)
			temp = temp->next;

		new->prev = temp;
		temp->next = new;
	}

	return (new);
}