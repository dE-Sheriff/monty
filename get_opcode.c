#include "monty.h"

/**
 * _get_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 * Return: pointer to the function that executes the opcode
 */
void _get_opcodes(void)
{
	int i;

	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	if (inputs->tok_count == 0)
		return;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, inputs->lines_tok[0]) == 0)
			break;
	}
	inputs->instruction->opcode = malloc(strlen(instruct[i].opcode) + 1);
	if (inputs->instruction->opcode == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	strcpy(inputs->instruction->opcode, instruct[i].opcode);
	inputs->instruction->f = instruct[i].f;
}
