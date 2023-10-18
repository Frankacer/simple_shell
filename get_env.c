#include "shell.h"

/**
 * _strncmp - compares n number of characters between two strings
 * @s1: first string input
 * @s2: second string input
 * @n: Number of characters to compare
 * Return: 0 if the comparism match, and <1 or >1 if otherwise.
 */
int _strncmp(char *s1, char *s2, int n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/**
 * get_env - would extract req value from the environment variable
 * @name: The name of the variable taken as parameter
 *
 * Return: pointer to the value in PATH variable / NULL WRT conditions
 */
char *get_env(char *name)
{
	int i, temp;
	char *var_line;
	char **env;

	env = environ;
	for (i = 0; env[i]; i++)
	{
		var_line = env[i];
		/*Check if the argument is of the form NAME=VALUE*/
		temp = _strncmp(var_line, name, _strlen(name));
		if ((temp == 0) && (var_line[_strlen(name)] == '='))
			return (var_line + _strlen(name) + 1);
	}
	return (NULL);
}
