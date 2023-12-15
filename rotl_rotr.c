#include "monty.h"
/**
 * rotl_el - function rotate the stack to the top
 * @stack: head of the stack
 * @line_number: number of args in the line
*/
void rotl_el(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
stack_t *last = *stack;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = *stack;
		(*stack)->prev = last;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next->next = NULL;
	}
}

/**
 * rotr_el - fuction rotate the stack to bottom
 * @stack: head of the stack
 * @line_number: number of args in the line
*/
void rotr_el(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
stack_t *first = *stack;
stack_t *last = *stack;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		*stack = last;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
	}
}
