#ifndef MONTY_H
#define MONTY_H

/* Including the most common libraries to work to */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Validate funcs */
int valid_push(char *number);
void validate_buffer(char *line, size_t line_num, stack_t **h, FILE *file_des);


/* Reader and executer */
void reader(char *file);
void executer(stack_t **h, char *opcode, int data, size_t line_num);


/* Opcode and struct funcs */
void exec_push(stack_t **head, int data);
void print_all(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void free_dlistint(stack_t *head);

#endif /* !MONTY_H */
