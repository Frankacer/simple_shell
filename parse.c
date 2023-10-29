#include "shell.h"
#include "main.h"

/**
 * parse_line - split input string into tokens
 * @line: input string
 *
 * Return: returns a pointer to a dynamically allocated
 * array of tokens, otherwise NULL.
*/
char **parse_line(char *line)
{
	int i = 0, count;
	char *temp_tok, *temp = _strdup(line);
	char **tokens;
	char delimiter[] = " ";

	/*count tokens*/
	temp_tok = strtok(temp, delimiter);
	for (count = 1; temp_tok != NULL; count++)
		temp_tok = strtok(NULL, delimiter);

	/*tokenize line*/
	tokens = malloc((count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Dynamic memory allocation failed!");
		exit(errno);
	}
	tokens[i] = _strdup(strtok(line, delimiter));
	while (tokens[i] != NULL)
	{
		i++;
		tokens[i] = _strdup(strtok(NULL, delimiter));
	}
	free(temp);
	return (tokens);
}

/**
 * get_input - reads and parse input from user
 * @cmd_buff: pointer to buffer that holds user input
 * @counter: pointer to an int that keeps track of loop runs
 *
 * Return: array of strings containing cmd entered
 * by user and its corresponding args, otherwise NULL.
 */
char **get_input(char **cmd_buff, int *counter)
{
	char **input;

	if (read_line(cmd_buff) == -1 && counter)
	{
		free(*cmd_buff);
		(*counter)++;
		_putchar('\n');
		exit(EXIT_SUCCESS);
	}
	if (**cmd_buff == '\0')
	{
		free(*cmd_buff);
		(*counter)++;
		return (NULL);
	}
	input = parse_line(*cmd_buff);
	free(*cmd_buff);
	return (input);
}
