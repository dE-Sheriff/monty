#include "monty.h"

/**
 * main - Executes the monty interpreter
 * @argc: argument count
 * @argv: argument strings
 * Return: int
*/

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	char *lines[2] = {NULL, NULL};
	char* token;
	int tok_count;
	FILE *input_file;

	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	input_file = fopen(argv[1], "r");
	if (!input_file)
	{
		fprintf(stderr, "L%s: unknown instruction <opcode>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	global_stack = NULL;

    while (getline(&line, &len, input_file) != -1) 
	{
		while (token != NULL)
		{
			for (tok_count = 0; tok_count < 2; tok_count++)
			{
				token = strtok(line, " ");
				lines[tok_count] = token;
				printf("%s\n", lines[tok_count]);
			}
		}
        line_number++;
	}
	return (0);
}
