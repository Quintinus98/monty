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

/**
 * _div -  divides the top two elements of the stack.
 * @stack: stack
 * @line_number: current line number in file
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *headptr = *stack, *temp;

	if (headptr == NULL || headptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = headptr->next;
	if (headptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	temp->n /= (headptr->n);
	_pop(stack, line_number);

	*stack = temp;
}

/**
 * _mul -  multiplies the top two elements of the stack.
 * @stack: stack
 * @line_number: current line number in file
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *headptr = *stack, *temp;

	if (headptr == NULL || headptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = headptr->next;
	temp->n *= (headptr->n);
	_pop(stack, line_number);

	*stack = temp;
}

/**
 * _mod -  modulus the top two elements of the stack.
 * @stack: stack
 * @line_number: current line number in file
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *headptr = *stack, *temp;

	if (headptr == NULL || headptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = headptr->next;
	temp->n %= (headptr->n);
	_pop(stack, line_number);

	*stack = temp;
}

/**
 * comments - Removes comments from execution
 * @buf: string buffer.
*/
void comments(char *buf)
{
	int i = 0;

	if (!buf)
		return;
	for (; buf[i] != '\0'; i++)
	{
		if (buf[i] == ' ' && buf[i + 1] == '#')
			buf[i + 1] = '\0';
		else if (buf[i] == '#' && buf[i + 1] == '\0')
			buf[i] = '\0';
		else if (buf[i] == '#' && i == 0)
		{
			buf[i] = '\0';
			break;
		}
	}
}
