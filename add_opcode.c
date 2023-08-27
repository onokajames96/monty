#include "monty.h"
/**
 * add - add elemnts on the stack.
 * @stack: doubly linked lists.
 * @line_number: the file line executed
 *
 *Return: void.
 */
void add(stack_t **stack, unsigned int line_number)
{

	if (!*stack || !(*stack)->next)
	{	
		fprintf(stderr, "L%u can't add, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}
