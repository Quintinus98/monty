#include "main.h"

/**
 * instructions - what to do
 * @s: string to match
 * Return: Null or function
*/
void (*instructions(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", insert},
		{"pall", display},
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
 * insert - inserts into stack
 * @stack: stack
 * @line_number: current line number in file
*/
void insert(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	(void)line_number;
	(void)stack;

	if (newNode == NULL)
		print_error("Error: malloc failed\n");

	if (!global.val)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newNode->n = global.val;
	newNode->prev = NULL;
	if (global.head == NULL)
	{
		newNode->next = NULL;
		global.head = newNode;
		return;
	}

	newNode->next = global.head;
	global.head->prev = newNode;
	global.head = newNode;
}

/**
 * display - displays all values in stack
 * @stack: stack
 * @line_number: current line number in file
*/
void display(stack_t **stack, unsigned int line_number)
{
	stack_t *headptr = (*stack);

	(void)line_number;
	while (headptr != NULL)
	{
		printf("%d\n", headptr->n);
		headptr = headptr->next;
	}
}
