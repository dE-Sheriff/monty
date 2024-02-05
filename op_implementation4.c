#include "monty.h"

/**
 * rotr - Implement the add opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

void rotr(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}


/**
 * _div - Implement the add opcode
 * @stack: the linked list or array struct
 * @line_number: the int to push to the stack
 * Return: Void
*/

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *stk_cpy1, *stk_cpy2, *stack_copy;

	(void) stack;
	if (inputs->stack_index < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all_memory();
		exit(EXIT_FAILURE);
	}
	stk_cpy1 = inputs->head;
	stk_cpy2 = stk_cpy1->next;

	if (stk_cpy1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all_memory();
		exit(EXIT_FAILURE);
	}

	stk_cpy2->n = stk_cpy2->n / stk_cpy1->n;
	stack_copy = inputs->head;
	inputs->head = stack_copy->next;
	free(stack_copy);

	inputs->stack_index -= 1;
}
