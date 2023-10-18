#include "shell.h"

/**
 * is_a_path - checks if a file exists and is executable
 * @cmd: pathname of file
 * Return: 1 on success, otherwise 0.
 */
int is_a_path(const char *cmd)
{
	if (access(cmd, F_OK | X_OK) == -1)
		return (1);
	return (0);
}
