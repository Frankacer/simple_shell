#include "shell.h"

/**
 * main - Entry point for the simple shell project
 * @ac: argument count variable
 * @av: argument vector to store pointer to string inputs
 * Return: Alway 0 (succes)
 */
int main(int ac, char **av)
{
	(void)ac;

	/*interactive mode*/
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		hsh_loop(av[0]);
	/*non-interactive mode*/
	else
		non_interact(av[0]);
	return (0);
}
