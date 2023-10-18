#include "shell.h"
#include "main.h"

/**
 * builtin_env - prints environment of current process
 */
void hsh_env(char **input, int *status)
{
	input[0] = "/usr/bin/env";
	if (status)
		*status = cmd_exec(input);
	else
		 cmd_exec(input);
}
