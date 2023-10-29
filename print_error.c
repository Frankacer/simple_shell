#include "main.h"

/**
 * print_error - prints error
 */
void print_error(int status, int count, char **input, char *prg_path)
{
	if (status == 2)
		_printf("%s: %d: %s: %s: %s\n", prg_path, count, input[0], "Illegal number", input[1]);
	else if (status == 127)
		_printf("%s: %d: %s: %s\n", prg_path, count, input[0], "not found");
}
