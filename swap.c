#include "monty.h"
/**
 * swap - swaps top of lits.
 * @stack: the pointer.
 * @line_number: line executed
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	if (*stack == NULL || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

