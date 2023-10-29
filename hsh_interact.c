#include "shell.h"
#include "main.h"

/**
 * hsh_loop - command loop
 * @prg_path: pathname of shell program
 */
void hsh_loop(char *prg_path)
{
	int count = 1, status = 0, hsh_status = 0;
	char *cmd_buff = NULL;
	char **input;

	while (1)
	{
		print_prompt("cisfun$ ");
		input = get_input(&cmd_buff, &count);
		if (input == NULL)
			continue;
		if (*input == NULL)
		{
			free_block(input);
			count++;
			continue;
		}
		if (check_builtin(input, prg_path, &count, 0, &status, &hsh_status) == 1)
			status = cmd_exec(input, &hsh_status);
		print_error(hsh_status, count, input, prg_path);
		free_block(input);
		count++;
	}
}
