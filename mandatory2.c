#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: stack
 * @line_number: current line number in file
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *headptr = *stack;

	if (headptr == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", headptr->n);
}

/**
 * _pop - removes the top element of the stack.
 * @stack: stack
 * @line_number: current line number in file
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *headptr = *stack;

	if (headptr == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = headptr->next;
	free(headptr);
}

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: stack
 * @line_number: current line number in file
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *headptr = *stack, *temp;

	if (headptr == NULL || headptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = headptr->next;
	if (temp->next)
		temp->next->prev = headptr;
	headptr->next = temp->next;
	temp->prev = NULL;
	temp->next = headptr;
	headptr->prev = temp;

	*stack = temp;
}

/**
 * _add -  adds the top two elements of the stack.
 * @stack: stack
 * @line_number: current line number in file
*/
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *headptr = *stack, *temp;

	if (headptr == NULL || headptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = headptr->next;
	temp->n += (headptr->n);
	_pop(stack, line_number);

	*stack = temp;
}

/**
 * _nop -  does nothing.
 * @stack: stack
 * @line_number: current line number in file
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
