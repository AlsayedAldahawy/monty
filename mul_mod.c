#include "monty.h"
/**
 * mul_el - function to mul the elements of the stack
 * @stack: the head of the stack
 * @line_number: the number of the args
 *
*/
void mul_el(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	remove_el(stack, line_number);
}

/**
 * mod_el - function to get modules of stack elements
 * @stack: head of the stack
 * @line_number: number of the args in line
*/
void mod_el(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	remove_el(stack, line_number);
}
