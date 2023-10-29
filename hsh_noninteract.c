#include "shell.h"
#include "main.h"

/**
 * non_interact - runt the shell in non interactive mode
 * @prg_path: string that holds program shell's pathname
 */
void non_interact(char *prg_path)
{
	char *cmd_buff = NULL;
	char **input;
	int status = 0, count = 0, hsh_status = 0;

	while (read_line(&cmd_buff) != -1)
	{
		count++;
		if (*cmd_buff == '\0')
		{
			free(cmd_buff);
			continue;
		}
		input = parse_line(cmd_buff);
		free(cmd_buff);
		if (*input == NULL)
		{
			free_block(input);
			continue;
		}
		if (check_builtin(input, prg_path, &count, 1, &status, &hsh_status)) /*returns 0 on success*/
			status = cmd_exec(input, &hsh_status);
		print_error(hsh_status, count, input, prg_path);
		free_block(input);
		cmd_buff = NULL;
	}
	free(cmd_buff);
	if (status > 0)
		exit(status);
	exit(hsh_status);
}
