#include "monty.h"

/**
 * free_all_memory - frees all allocated memory
*/

void free_all_memory(void)
{
	close_input_file();
	free_tokens();
	free_inputs();
}
