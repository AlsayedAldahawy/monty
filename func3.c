#include "monty.h"
/**
 * push_el - function to insert elements into stack
 * @stack: head of linked list.
 * @value: value which need to insert.
*/
void push_el(stack_t **stack, unsigned int value)
{
stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * p_all - function to print all elements of stack.
 * @stack: head of the linked list.
 * @line_number: line to interpreted by monty
*/
void p_all(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pchar_el - function print char at top of stack
 * @stack: head of the stack
 * @line_number: number of args in the line
*/
void pchar_el(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);

	remove_el(stack, line_number);
}

/**
 * pstr_el - function print string of stack
 * @stack: head of the stack
 * @line_number: number of args in the line
*/
void pstr_el(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
stack_t *curr = *stack;

	while (curr != NULL && curr->n != 0 && isascii(curr->n))
	{
		printf("%c", curr->n);
		curr = curr->next;
	}
	putchar('\n');
}
