#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#define Buffsize 40
#define DELIMS 
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 *struct global_var - global variables.
 *@myFILe: filename.
 *@buffer: gets line. 
 *@temp: gets the line counter.
 *@dict: dictionary instruction.
 *@head: the pointer to the list.
 *@line_number: stores value
 *
 */
typedef struct global_var
{
	FILE *myFILE;
	char *buffer;
	size_t temp;
	instruction_t *dict;
	stack_t *head;
	unsigned int line_number;
	int MODE;
} vars;
extern vars var;
int start_vars(vars *var);
instruction_t *create_instru();
int funct_monty(vars *var, char *op);
void free_all(void);
int is_a_digit(char *str);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */
