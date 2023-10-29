#include "shell.h"
#include "main.h"

/**
 * check_builtin - handles builtins
 * @input: array of tokes entered by user
 * @cmd_buff: user input string
 * @status: exit status of executed command
 * Return: returns 0 on success, otherwise it returns 1.
 */
int check_builtin(char **input, char *prg_path, int *count, int flag, int *status, int *hsh_status)
{
	int i;
	char *builtin[] = {"exit", "setenv", "unsetenv", "cd", NULL};

	for (i = 0; builtin[i]; i++)
	{
		if (_strcmp(input[0], builtin[i]) == 0)
		{
			if (i == 0)
			{
				if (input[1] == NULL)
				{
					free_block(input);
					if (*status > 0)
						exit(*status);
					exit(*hsh_status);
				}
				if (is_valid_arg(input[1]) == 1)
				{
					*hsh_status = 2;
					print_error(*hsh_status, *count, input, prg_path);
					if (!flag)
						return (0);
					free_block(input);
					exit(2);
				}
				*hsh_status = _atoi(input[1]) % 256;
				free_block(input);
				exit(*hsh_status);
			}
			*hsh_status = 0;
			*status = 0;
		}
	}
	return (1);
}
