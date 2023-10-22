#include "monty.h"

global_t global = {NULL, NULL, NULL, 1};

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
		comments(dynline);
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
