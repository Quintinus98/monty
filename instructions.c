#include "monty.h"

/**
 * instructions - what to do
 * @s: string to match
 * Return: Null or function
*/
void (*instructions(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, s) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL);
}

/**
 * _push - inserts into stack
 * @stack: stack
 * @line_number: current line number in file
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	char *endptr;
	long val;

	(void)stack;
	if (newNode == NULL)
		print_error("Error: malloc failed");

	errno = 0;
	val = strtol(global.arg, &endptr, 10);
	if (!global.arg || errno != 0 || endptr == global.arg || *endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newNode->n = val;
	newNode->prev = NULL;
	if (global.head)
		global.head->prev = newNode;
	newNode->next = global.head;
	global.head = newNode;
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
