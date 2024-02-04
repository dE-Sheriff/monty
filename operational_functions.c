#include "monty.h"

/**
 * start_arguments - initializes arguments for the input
 * Return: arg_t
*/

void start_arguments()
{
	inputs = malloc(sizeof(arg_t));
	if (inputs == NULL)
		malloc_err();
	inputs->instruction = malloc(sizeof(instruction_t));
	if (inputs->instruction == NULL)
		malloc_err();

	inputs->text_chunk = NULL;
	inputs->line = NULL;
	inputs->line_number = 1;
	inputs->lines_tok = NULL;
	inputs->stack_index = 0;
	inputs->head = NULL;
}

/**
 * tokenize_line - tokinized read line fron text_chunk
*/

void tokenize_line(void)
{
	int i, x = 0;
	char *token = NULL, *linecopy = NULL;

	linecopy = malloc(sizeof(char) * (strlen(inputs->line)
	+ 1));
	if (linecopy == NULL)
		malloc_err();
	
	strcpy(linecopy, inputs->line);
	inputs->tok_count = 0;

	token = strtok(linecopy, " \n");
	while (token)
	{
		inputs->tok_count++;
		token = strtok(NULL, " \n");
	}

	inputs->lines_tok = malloc(sizeof(char *) *
	(inputs->tok_count + 1));

	strcpy(linecopy, inputs->line);
	token = strtok(linecopy, " \n");
	while (token)
	{
		inputs->lines_tok[x] = malloc(sizeof(char *) *
		strlen(token));
		if (inputs->lines_tok[x] == NULL)
		{
			malloc_err();
			/* Free previously allocated memory before returning */
			for (i = 0; i < x; i++)
			{
			    free(inputs->lines_tok[i]);
			}
			free(inputs->lines_tok);
			free(linecopy);
			return;
		}
		strcpy(inputs->lines_tok[x], token);
		token = strtok(NULL, " \n");
		x++;
	}
	inputs->lines_tok[x] = NULL;
	free(linecopy);

}

void free_input(arg_t *inputs)
{
    if (inputs != NULL)
    {
        free(inputs->text_chunk);
        free(inputs->line);
        free(inputs);
    }
}