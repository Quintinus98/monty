#include "monty.h"

/**
 * _pchar -  prints the char at the top of the stack.
 * @stack: stack
 * @line_number: current line number in file
*/
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * _pstr -  prints the char at the top of the stack.
 * @stack: stack
 * @line_number: current line number in file
*/
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *headptr = *stack;

	(void)line_number;
	while (headptr && headptr->n > 0 && headptr->n < 128)
	{
		printf("%c", headptr->n);
		headptr = headptr->next;
	}
	printf("\n");
}

/**
 * _rotl -  rotates the stack to the top.
 * @stack: stack
 * @line_number: current line number in file
*/
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp;

	(void)line_number;
	if (current == NULL)
		return;
	temp = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = temp->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
}

/**
 * _rotr -  rotates the stack to the bottom.
 * @stack: stack
 * @line_number: current line number in file
*/
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (!current || current->next == NULL)
		return;

	current->prev->next = NULL;
	current->next = *stack;
	current->prev = NULL;
	(*stack)->prev = current;
	*stack = current;
}

/**
 * _queue -  sets the format of the data to a queue (FIFO).
 * @stack: stack
 * @line_number: current line number in file
*/
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	global.is_stack = 0;
}
