#include "monty.h"

/**
 * string_to_arr - splits string
 * @s: array of string character.
 * @sep: seperator.
 * Return: an array of each word of the string.
*/
char **string_to_arr(char *s, char *sep)
{
	int i = 0;
	char **arr, *token;

	/** Create Dynamic array */
	arr = malloc(30 * sizeof(char *));
	if (arr == NULL)
		return (NULL);

	/** Get Token and use for loop to extract the rest. */
	token = strtok(s, sep);
	while (token != NULL)
	{
		arr[i] = token;
		token = strtok(NULL, sep);
		i++;
	}
	arr[i] = NULL;

	if (arr[0] == NULL)
	{
		free(arr);
		arr = NULL;
	}

	return (arr);
}

/**
 * free_head - Frees head
 * @head: head of doubly linked list
*/
void free_head(stack_t **head)
{
	stack_t *nextNode, *currentNode;

	if (head == NULL)
		return;

	currentNode = *head;
	while (currentNode)
	{
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}
	*head = NULL;
}
