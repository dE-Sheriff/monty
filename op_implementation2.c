#include "monty.h"
#include <stdio.h>

/**
 * add - Implement the add opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *stk_cpy1, *stk_cpy2, *stack_copy;

	(void) stack;
	if (inputs->stack_index < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all_memory();
		exit(EXIT_FAILURE);
	}

	stk_cpy1 = inputs->head;
	stk_cpy2 = stk_cpy1->next;

	stk_cpy2->n = stk_cpy1->n + stk_cpy2->n;

	stack_copy = inputs->head;
	inputs->head = stack_copy->next;
	free(stack_copy);

	inputs->stack_index -= 1;
}

/**
 * nop - Implement the add opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * queue - Implement the add opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * stack - Implement the add opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub - Implement the add opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

void sub(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
