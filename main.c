#include "monty.h"

global_t global = {NULL, NULL, NULL};

/**
 * main - Main program execution
 * @argc: argument count
 * @argv: argument list
 * Return: 0 on success
*/
int main(int argc, char **argv)
{
	size_t len = 0;
	int cnt = 0, ret;
	ssize_t nread;
	FILE *stream;
	char *dynline = NULL, **codes = NULL;

	if (argc != 2)
		print_error("USAGE: monty file");

	stream = fopen(argv[1], "r");
	if (!stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	nread = getline(&dynline, &len, stream);
	for (; nread != -1; nread = getline(&dynline, &len, stream))
	{
		cnt++;
		codes = string_to_arr(dynline, " \n");
		if (!codes)
			continue;
		ret = readmonty(codes, cnt);
		free(codes);
		if (ret == 1)
			break;
	}
	free_head(&global.head);
	free(dynline);
	fclose(stream);
	if (ret == 1)
		exit(EXIT_FAILURE);

	return (0);
}

/**
 * readmonty - reads monty files
 * @codes: takes monty codes
 * @cnt: number of lines
 * Return: 0 or 1
*/
int readmonty(char **codes, int cnt)
{
	void (*instruction)(stack_t **stack, unsigned int line_number);

	instruction = instructions(codes[0]);
	if (!instruction)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", cnt, codes[0]);
		return (1);
	}
	global.opcode = codes[0];
	global.arg = codes[1];

	instruction(&global.head, cnt);
	return (0);
}

/**
 * print_error - Prints error to stderr and exits the program
 * @msg: error message to print
*/
void print_error(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}
