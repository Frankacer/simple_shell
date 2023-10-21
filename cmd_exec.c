#include "shell.h"

/**
 * cmd_exec - executes a command
 * @input: array of strings containing user input cmd and args
 *
 * Return: 0 on success, otherwise -1.
 */
int cmd_exec(char **input, int *hsh_status)
{
	char *abs_path;
	pid_t pid;
	int status = 0, exit_code = 0;

	if (is_a_path(*input) == 0)
		abs_path = _strdup(*input);
	else
		abs_path = find_exe(*input);

	if (abs_path == NULL)
	{
		*hsh_status = 127;
		return (127);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork process failed");
		exit(errno);
	}
	else if (pid == 0)
	{
		if (execve(abs_path, input, environ) == -1)
		{
			perror("execve failed");
			exit(errno);
		}
	}
	if (pid > 0)
		wait(&status);
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	free(abs_path);
	return (exit_code);
}
