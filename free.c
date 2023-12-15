#include "monty.h"
/**
 * free_nodes - fuction to free the stack
 * @stack: head of the stack
*/
void free_nodes(stack_t **stack)
{
stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = temp->next;
		free(temp);
	}
}

/**
 * nop - function that not print anything
 * @stack: head of the stack.
 * @line_number: number of args in the line
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
