#include "monty.h"

/**
 * malloc_err
*/

void malloc_err(void)
{
	fprintf(stderr, "malloc failed\n");
	exit(EXIT_FAILURE);
	free_input(inputs);
}

/**
 * text_chunk_err - error message when file opening fails
 * @fileTitle: name of the file in err
 * Return: Void
*/

void text_chunk_err(char *fileTitle)
{
		fprintf(stderr, "Error: Can’t open file %s\n", fileTitle);
		free_input(inputs);
		exit(EXIT_FAILURE);
}
