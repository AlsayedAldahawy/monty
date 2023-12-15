#include "monty.h"
/**
 * execute_monty - function to execute monty script on the stack.
 * @line: line to be get from user
 * @line_number: argument number of the line
 * @stack: head of the stack
*/
void execute_monty(char *line, unsigned int line_number, stack_t **stack)
{
int i;
char *arg;
char *op = strtok(line, " \t\n");
instruction_t monty[] = {
	{"push", push_el}, {"pall", p_all}, {"pint", p_int}, {"rotl", rotl_el},
	{"pop", remove_el}, {"swap", swap_nodes}, {"add", add_el}, {"rotr", rotr_el},
	{"sub", sub_el}, {"div", div_el}, {"mul", mul_el}, {"pchar", pchar_el},
	{"mod", mod_el}, {"nop", nop}, {"pstr", pstr_el}, {NULL, NULL}
};

	if (op == NULL || op[0] == '#')
		return;
	for (i = 0; monty[i].opcode != NULL; i++)
	{
		if (strcmp(op, monty[i].opcode) == 0)
		{
			if (strcmp(op, "push") == 0)
			{
				arg = strtok(NULL, " \t\n");
				if (arg == NULL || atoi(arg) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				monty[i].f(stack, atoi(arg));
			}
			else
				monty[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}

/**
 * p_int - function to convert arg. to int and print all.
 * @stack: head of the stack.
 * @line_number: number of arguments in line
*/
void p_int(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * remove_el - function to pop elements from stack
 * @stack: head of the stack
 * @line_number: number of args in line.
*/
void remove_el(stack_t **stack, unsigned int line_number)
{
stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}


	top = *stack;
	*stack = top->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(top);
}

