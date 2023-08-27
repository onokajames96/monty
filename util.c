#include "monty.h"
/**
 * start_vars - initializes the global variables used.
 * @var: Global variables.
 * Return: Success 0, 1 Failed
 */
int start_vars(vars *var)
{
	var->myFILE = NULL;
	var->buffer = NULL;
	var->temp = 0;
	var->dict = create_instruct();
	if (var->dict == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}
/**
 * funct_monty - monty Functions
 * @var: Global variables
 * @op: executed command
 * Return: Nothing
 */
int funct_monty(vars *var, char *opcode)
{
	int k;

	for (k = 0; var->dict[k].opcode; k++)
		if (strcmp(opcode, var->dict[k].opcode) == 0)
		{
			if (!var->dict[k].f)
				return (EXIT_SUCCESS);
			var->dict[k].f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			var->line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
/**
 * free_all - frees all allocated mem.
 * Return: Nothing
 */
void free_all(void)
{
	if (var.buffer != NULL)
		free(var.buffer);
	if (var.myFILE != NULL)
		fclose(var.myFILE);
	free(var.dict);
	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}
		free(var.head);
	}
}
