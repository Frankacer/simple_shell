#include "shell.h"
#include "main.h"

/**
 * hsh_env - prints environment of current process
 * @input: pointer to array of input tokens
 * @status: pointer to exit code variable
 */
void hsh_env(char **input, int *status)
{
	input[0] = "/usr/bin/env";
	if (status)
		*status = cmd_exec(input);
	else
		 cmd_exec(input);
}
