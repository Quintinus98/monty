#include "monty.h"

/**
 * addnode - adds node at the beginning.
 * @val: value to add.
*/
void addnode(int val)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
		print_error("Error: malloc failed");
	newNode->n = val;
	newNode->prev = NULL;
	newNode->next = global.head;

	if (global.head)
		global.head->prev = newNode;
	global.head = newNode;
}

/**
 * addnode_end - adds node at the end
 * @val: value to add.
*/
void addnode_end(int val)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	stack_t *last = global.head;

	if (newNode == NULL)
		print_error("Error: malloc failed");

	newNode->n = val;
	newNode->next = NULL;

	if (global.head == NULL)
	{
		newNode->prev = NULL;
		global.head = newNode;
		return;
	}
	while (last->next != NULL)
		last = last->next;

	last->next = newNode;
	newNode->prev = last;
}
