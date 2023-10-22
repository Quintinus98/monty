#include "monty.h"
/**
 * _rev -  reverse the stack to the top.
 * @stack: stack
 * @line_number: current line number in file
*/
void _rev(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *prev = NULL, *next = NULL;

	(void)line_number;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*stack = prev;
}
