#include "monty.h"

/**
 * _sub -  subtracts the top two elements of the stack.
 * @stack: stack
 * @line_number: current line number in file
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *headptr = *stack, *temp;

	if (headptr == NULL || headptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = headptr->next;
	temp->n -= (headptr->n);
	_pop(stack, line_number);

	*stack = temp;
}