#include "monty.h"

arg_t *inputs = NULL;

/**
 * main - Executes the monty interpreter
 * @argc: argument count
 * @argv: argument strings
 * Return: int
*/

int main(int argc, char *argv[])
{
	size_t len = 0;
	stack_t *stack = NULL;

	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	start_arguments();
	get_text(argv[1]);
	
	

    while (getline(&inputs->line, &len, inputs->text_chunk) != -1)
	{
		tokenize_line();
		if (inputs->tok_count > 0)
		{
			_get_opcodes();
			exec_opcode(&*stack);
			free_tokens();
		}
		inputs->line_number++;
	}
	free_all_memory();
	return (0);
}
