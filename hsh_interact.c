#include "shell.h"
#include "main.h"

/**
 * hsh_loop - command loop
 * @prg_path: pathname of shell program
 */
void hsh_loop(char *prg_path)
{
	int counter = 1;
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
		if (check_builtin(input, &cmd_buff, NULL) == 0)
			;
		else if ((cmd_exec(input)) == 127)
			_printf("%s: %d: %s: %s\n", prg_path, counter, *input, "not found");

		free(input);
		free(cmd_buff);
		counter++;
	}
}
