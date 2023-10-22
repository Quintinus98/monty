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
