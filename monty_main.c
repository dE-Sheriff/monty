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
	
	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	start_arguments();
	get_text(argv[1]);

    while (getline(&inputs->line, &len, inputs->text_chunk) != -1)
	{
		printf("Processing line %d: %s", inputs->line_number, inputs->line);
		tokenize_line();
		printf("Tokenized: ");
		printf("\n");
		if (inputs->tok_count > 0)
		{
			_get_opcodes();
			exec_opcode();
		}
		inputs->line_number++;
	}
	return (0);
}
