#include "shell.h"
#include "main.h"

/**
 * hsh_loop - command loop
 * @prg_path: pathname of shell program
 */
void hsh_loop(char *prg_path)
{
	int counter = 1, hsh_status = 0;
	char *cmd_buff = NULL;
	char **input;

	while (1)
	{
		print_prompt("cisfun$ ");
		input = get_input(&cmd_buff, &counter);
		if (input == NULL)
		{
			free(cmd_buff);
			counter++;
			continue;
		}
		if (*input == NULL)
		{
			free(input);
			free(cmd_buff);
			counter++;
			continue;
		}
		if (check_builtin(input, &cmd_buff, &hsh_status) == 1)
			cmd_exec(input, &hsh_status);
		if (hsh_status > 0)
			print_error(hsh_status, input, prg_path);
		free(input);
		free(cmd_buff);
		counter++;
	}
}
