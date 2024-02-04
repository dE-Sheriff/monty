#include "monty.h"

/**
 * close_input_file - closes opend file
 * 
*/

void close_input_file(void)
{
	if (inputs->text_chunk == NULL)
		return;
		
	fclose(inputs->text_chunk);
	inputs->text_chunk = NULL;
}


/**
 * free_tokens - frees allocated tokens
*/
void free_tokens(void)
{
	int i;

	if (inputs->lines_tok == NULL)
		return;
	
	for (i = 0; inputs->lines_tok[i]; i++)
	{
		free(inputs->lines_tok[i]);
	}
	free(inputs->lines_tok);
	inputs->lines_tok = NULL;
}

/**
 * free_stack - frees allocated memory
 * in a stack
*/

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	
	if (head->next != NULL)
		free(head->next);
	free(head);
}

/**
 * free_head - frees allocated memory
 * for a stack
*/

void free_head(void)
{
	if (inputs->head == NULL)
		return;
	free_stack(inputs->head);
	inputs->head = NULL;
}

/**
 * free_inputs - frees memory allocated for
 * input pointers
*/

void free_inputs(void)
{
	if (inputs == NULL)
		return;
	
	if (inputs->instruction)
	{
		free(inputs->instruction);
		inputs->instruction = NULL;
	}
	free_head();

	if (inputs->line)
	{
		free(inputs->line);
		inputs->line = NULL;
	}
	free(inputs);
}
