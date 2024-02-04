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
	int converted_value;

	if (inputs->tok_count == 0 || (isnumber(inputs->lines_tok[1])))
	{
		free_input(inputs);
		fprintf(stderr, "L%d: unknown instruction %s", line_number,
		inputs->lines_tok[0]);
		exit(EXIT_FAILURE);
	}

	(void) line_number;

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_err();

	(*stack)->next = (*stack)->prev = NULL;
	converted_value = atoi(inputs->lines_tok[1]);
	if (converted_value == 0 && inputs->lines_tok[1][0] != '0')
	{
		free_input(inputs);
		fprintf(stderr, "L%d: invalid number %s\n",
		line_number, inputs->lines_tok[1]);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = converted_value;
	if (inputs->head != NULL)
	{
		(*stack)->next = inputs->head;
		inputs->head->prev = *stack;
	}
	inputs->head = *stack;
	inputs->stack_index++;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *list;

	(void)line_number;
	(void)stack;

	if (inputs->head == NULL)
		return;
	list = inputs->head;
	while (list)
	{
		printf("%d\n", list->n);
		list = list->next;
	}
}
