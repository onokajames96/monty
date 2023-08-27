#include "monty.h"
/**
 * pop - deletes the items on top list.
 * @stack: the pointer.
 * @line_number: execution.
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u can't pop an empty stack\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	*stack = temp-> next;
	if (temp-> next)
		temp->next->prev = NULL;
			free(temp);
}
