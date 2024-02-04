#include "monty.h"

/**
 * exec_opcode - executes detected opcode
*/

void exec_opcode()
{
	stack_t **stack = NULL;

	if (inputs->tok_count == 0)
		return;

	inputs->instruction->f(stack, inputs->line_number);
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