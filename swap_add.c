#include "monty.h"
/**
 * swap_nodes - function to swap nodes.
 * @stack: head of the stack
 * @line_number: number of args in the line
*/
void swap_nodes(stack_t **stack, unsigned int line_number)
{
stack_t *first = *stack;
stack_t *second = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;

	second->prev = first->prev;

	first->prev = second;
	second->next = first;
	*stack = second;
}

/**
 * add_el - function that add the first 2 elements of the stack
 * @stack: head of the stack
 * @line_number: number of the args in the line
*/
void add_el(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	remove_el(stack, line_number);
}
