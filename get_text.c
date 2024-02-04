#include "monty.h"

/**
 * get_text - gets stream of text from file
 *
*/

void get_text(char *fileTitle)
{
	inputs->text_chunk = fopen(fileTitle, "r");
	if (!inputs->text_chunk)
	{
		fclose(inputs->text_chunk);
		text_chunk_err(fileTitle);
	}
}
