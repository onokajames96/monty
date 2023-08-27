#include "monty.h"
vars var;
/**
 *push - insert or push an element into the of the stack.
 *@stack: doubly lists
 *@line_number: number
 *
 *Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	char *number;

	number = strtok(NULL, " \r\t\n");
	if (number == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	head->n = atoi(number);
	head->prev = NULL;
	head->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = head;

	*stack = head;
}

/**
 * is_digit - Clean all program mallocs
 * @string: validated number.
 * Return: Success 0, 1 Failed
 */
int is_digit(char *str)
{
	int k;

	for (k = 0; str[k]; k++)
	{
		if (str[k] < 48 || str[k] > 57)
			return (1);
	}
	return (0);
}
