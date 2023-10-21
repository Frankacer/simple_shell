#include "shell.h"
#include "main.h"

/**
 * check_builtin - handles builtins
 * @input: array of tokes entered by user
 * @cmd_buff: user input string
 * @status: exit status of executed command
 * Return: returns 0 on success, otherwise it returns 1.
 */
int check_builtin(char **input, char **cmd_buff, int *status)
{
	int i;
	char *builtin[] = {"env", "exit", "setenv", "unsetenv", "cd", NULL};

	for (i = 0; builtin[i]; i++)
	{
		if (_strcmp(input[0], builtin[i]) == 0)
		{
			if (i == 0)
			{
				hsh_env(input, status);
				return (0);
			}
			else if (i == 1)
			{
				if (input[1] == NULL)
				{
					free(input);
					free(*cmd_buff);
					exit(EXIT_SUCCESS);
				}
				*status = _atoi(input[1]) % 256;
				free(input);
				free(*cmd_buff);
				exit(*status);
			}
		}
	}
	return (1);
}
