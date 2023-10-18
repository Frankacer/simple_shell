#include "shell.h"

/**
 * read_line - Resp6onsible for collecting the user input from stdin
 * @cmd_buff: pointer to a dynamic memory for storing user input
 * Return: returns number of char read on success and -1 on failure.
 */
ssize_t read_line(char **cmd_buff)
{
	int i = 0;
	size_t n = 0;
	ssize_t get = 0;

	get = getline(&(*cmd_buff), &n, stdin);

	if (get == -1)
		return (-1);

	while (*(*cmd_buff + i))
	{
		if (*(*cmd_buff + i) == '\n')
		{
			*(*cmd_buff + i) = '\0';
				break;
		}
		i++;
	}
	return (get);
}
