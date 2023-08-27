#include "monty.h"
/**
 * pint - Prints the list.
 * @stack: pointer.
 * @line_number: the number. 
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
