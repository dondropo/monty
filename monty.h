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

/**
 * struct global_val_s - Global struct for better handling
 * @buffer: string per line of the file
 * @file_des: file descriptor
 * @head: head of the list
 */

typedef struct global_val_s
{
	char *buffer;
	FILE *file_des;
	stack_t *head;

} global_t;

global_t global;


/* Validate funcs */
int valid_push(char *number);
void validate_buffer(char *line, size_t line_num, stack_t **h);
void error_handler(int type_err, char *opcode, unsigned int line_num);
void clean_memory(void);


/* Reader and executer */
void reader(char *file);
int executer(stack_t **h, char *opcode, int data, size_t line_num);


/* Opcode and struct funcs */
void exec_push(stack_t **head, int data);
void print_all(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void free_dlistint(stack_t *head);
void swap(stack_t **head, unsigned int line_number);
void pop_element(stack_t **head, unsigned int line_num);
void nope(stack_t **head, unsigned int line_num);
void add(stack_t **head, unsigned int line_num);
void sub(stack_t **head, unsigned int line_num);
void mul(stack_t **head, unsigned int line_num);
void pchar(stack_t **head, unsigned int line_num);
void mod(stack_t **head, unsigned int line_num);
void pstr(stack_t **head, unsigned int line_num);
void _div(stack_t **head, unsigned int line_num);

#endif /* !MONTY_H */
