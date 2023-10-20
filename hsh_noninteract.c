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
	int status = 0;

	while (read_line(&cmd_buff) != -1)
	{
		if (*cmd_buff == '\0')
		{
			free(cmd_buff);
			continue;
		}
		input = parse_line(cmd_buff);
		if (*input == NULL)
		{
			free(input);
			free(cmd_buff);
			continue;
		}
		if (check_builtin(input, &cmd_buff, &status)) /*returns 0 on success*/
		{
			status = cmd_exec(input);
			if (status > 0)
			{
				if (status == 127)
					_printf("%s: %d: %s: %s\n", prg_path, 1, *input, "not found");
				free(input);
				free(cmd_buff);
				break;
			}
		}
		free(input);
		free(cmd_buff);
		cmd_buff = NULL;
	}
	free(cmd_buff);
	exit(status);
}
