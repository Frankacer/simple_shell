#include "shell.h"

/**
 * is_a_path - checks if a file exists and is executable
 * @cmd: pathname of file
 * Return: 0 on success, otherwise 1.
 */
int is_a_path(const char *cmd)
{
	if (cmd[0] == '/' || cmd[1] == '/' || cmd[2] == '/')
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (0);
	}
	return (1);
}
