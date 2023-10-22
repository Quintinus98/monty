#include "monty.h"

/**
 * _stack -  sets the format of the data to a stack (LIFO).
 * @stack: stack
 * @line_number: current line number in file
*/
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	global.is_stack = 1;
}
