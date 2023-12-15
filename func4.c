#include "monty.h"
/**
 * sub_el - function to sub elements of the stack
 * @stack: head of the stack
 * @line_number: number of args
 *
*/
void sub_el(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	remove_el(stack, line_number);
}

/**
 * div_el - function to divide the elements of the stack
 * @stack: head of the stack
 * @line_number: number of args
*/
void div_el(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	remove_el(stack, line_number);
}
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

