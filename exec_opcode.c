#include "monty.h"

/**
 * exec_opcode - executes detected opcode
*/

void exec_opcode()
{
	stack_t *stack;
	if (inputs->tok_count == 0)
		return;

	stack = NULL;
	inputs->instruction->f(&stack, inputs->line_number);
}

/**
 *void exec_opcode()
 *{
 *	if (inputs->tok_count == 0)
 *		return;
 *
 *	inputs->instruction->f(&(inputs->head), inputs->line_number);
 *}
*/