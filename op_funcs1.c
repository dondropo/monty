#include "monty.h"

/**
 * free_dlistint - Function that frees a list
 * @head: first element of the list
 */
void free_dlistint(stack_t *head)
{
	stack_t *temporal, *saver;

	temporal = head;

	while (temporal != NULL)
	{
		saver = temporal->next;
		free(temporal);
		temporal = saver;
	}
}

/**
 * print_all - function that prints all the
 * elements in the stack
 * @stack: pointer to the stack
 * @line_num: number of the line used
 * Return: none
 */
void print_all(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	(void)line_num;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - prints the value at the top
 * of the stack
 * @stack: pointer to the stack
 * @line_num: number of the line used
 * Return: none
 */

void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	if (tmp == NULL || !*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_num);
		clean_memory();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * exec_push - Execute the opcode push
 * @head: pointer to head of the stack
 * @data: value to put in the stack
 * Return: none
 */

void exec_push(stack_t **head, int data)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: Malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = data;

	if (!*head)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}
