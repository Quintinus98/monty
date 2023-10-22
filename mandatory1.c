#include "monty.h"

/**
 * _push - inserts into stack
 * @stack: stack
 * @line_number: current line number in file
*/
void _push(stack_t **stack, unsigned int line_number)
{
	char *endptr;
	long val;

	(void)stack;
	errno = 0;
	val = strtol(global.arg, &endptr, 10);
	if (!global.arg || errno != 0 || endptr == global.arg || *endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (stack == NULL)
		return;

	if (global.is_stack == 1)
		addnode(val);
	else
		addnode_end(val);

}

/**
 * _pall - displays all values in stack
 * @stack: stack
 * @line_number: current line number in file
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *headptr = (*stack);

	(void)line_number;
	while (headptr != NULL)
	{
		printf("%d\n", headptr->n);
		headptr = headptr->next;
	}
}
