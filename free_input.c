#include "shell.h"

/**
 * free_block - frees a block of memory blocks
 * @input: an array of strings
 */
void free_block(char **input)
{
	int i;

	for (i = 0; input[i] != NULL; i++)
		free(input[i]);
	free(input);
}
