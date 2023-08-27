#include "monty.h"
#include <stdio.h>
/**
 * main - entry point.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: on success 0, 1 if failed.
 */
int main(int argc, char *argv[])
{
	char *op;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (start_vars(&var) != 0)
		exit(EXIT_FAILURE);

	var.myFILE = fopen(argv[1], "r");
	if (!var.myFILE)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_all();
		exit(EXIT_FAILURE);
	}

	while (getline(&var.buffer, &var.temp, var.myFILE) != -1)
	{
		op = strtok(var.buffer, " \r\t\n");
		if (!op)
			if (funct_monty(&var, op) == EXIT_FAILURE)
			{
				free_all();
				exit(EXIT_FAILURE);
			}
		var.line_number++;
	}

	free_all();

	exit(EXIT_SUCCESS);
}
