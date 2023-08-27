#include "monty.h"
/**
 * create_instruct - creates  functions dictionary
 * Return: dictionary pointer.
 */
instruction_t *create_instruct()
{
instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

if (!ptr)
{
fprintf(stderr, "Error: malloc failed\n");
return (NULL);
}
ptr[0].opcode = "pall", ptr[0].f = pall;
ptr[1].opcode = "push", ptr[1].f = push;
ptr[2].opcode = "pint", ptr[2].f = pint;
ptr[3].opcode = "pop", ptr[3].f = pop;
ptr[4].opcode = "swap", ptr[4].f = swap;
ptr[5].opcode = "add", ptr[5].f = add;
ptr[6].opcode = "nop", ptr[6].f = NULL;
return (ptr);
}
