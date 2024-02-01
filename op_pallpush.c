#include "monty.h"
#include <stdio.h>

/**
 * push - Implement the push opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

void push(stack_t **stack, unsigned int line_number)
{
	unsigned int value = line_number;
	stack_t *new_n;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_n = malloc(sizeof(stack_t));
	if (!new_n)
	{
		fprintf(stderr, "malloc err\n");
		exit(EXIT_FAILURE);
	}

	new_n->n = value;

	new_n->next = *stack;
	*stack = new_n;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *list;
	
	(void)line_number;
	list = *stack;
	while (list)
	{
		printf("%d\n", list->n);
		list = list->next;
	}
}
