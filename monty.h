#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variables
 * @head: head linked list
 * @opcode: op code
 * @arg: character to be converted.
*/
typedef struct global_s
{
	stack_t *head;
	char *opcode;
	char *arg;
} global_t;

extern global_t global;

char **string_to_arr(char *s, char *sep);
void print_error(char *msg);
void (*instructions(char *s))(stack_t **stack, unsigned int line_number);
void free_head(stack_t **head);
int readmonty(char **codes, int cnt);

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);

#endif
