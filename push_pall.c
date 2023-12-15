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
