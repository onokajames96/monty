#include "monty.h"
/**
 * pall - prints lists of elements in stack.
 * @stack: pointer to the head of stack
 * @line_number: number.
 *
 *Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *itarator = *stack;

    (void) line_number;

    while (itarator)
    {
        printf("%d\n", itarator->n);
        itarator = itarator->next;
    }
}
