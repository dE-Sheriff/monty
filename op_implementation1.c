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

	printf("num of token: %d\n", inputs->tok_count);
	printf("node value: %s\n", inputs->lines_tok[1]);
	if (inputs->tok_count == 0 || !(isnumber(inputs->lines_tok[1])))
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

/**
 * pall - Implement the pall opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

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

/**
 * pint - Implement the pall opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (inputs->head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all_memory();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", inputs->head->n);
}

/**
 * pop - Implement the pop opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_copy;
	(void) stack;

	if (inputs->head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all_memory();
		exit(EXIT_FAILURE);
	}
	stack_copy = inputs->head;
	inputs->head = stack_copy->next;
	free(stack_copy);
}

/**
 * swap - Implement the swap opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *stk_cpy1, *stk_cpy2;

	(void) stack;
	if (inputs->stack_index < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all_memory();
		exit(EXIT_FAILURE);
	}

	stk_cpy1 = inputs->head;
	stk_cpy2 = stk_cpy1->next;
	stk_cpy1->next = stk_cpy2->next;
	if (stk_cpy1->next)
		stk_cpy1->next->prev = stk_cpy1;
	stk_cpy2->next = stk_cpy1;
	stk_cpy1->prev = stk_cpy2;
	stk_cpy2->prev = NULL;
	inputs->head = stk_cpy2;
}
