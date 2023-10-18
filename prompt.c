#include "shell.h"

/**
 * print_prompt - prints the prompt
 * @prompt: prompt string
 */
void print_prompt(char *prompt)
{
	ssize_t bytes_written = 0, sizeof_prompt = _strlen(prompt);

	while (sizeof_prompt > 0)
	{
		bytes_written = write(STDOUT_FILENO, prompt, sizeof_prompt);
		if (bytes_written == -1)
			perror("Error");
		prompt += bytes_written;
		sizeof_prompt -= bytes_written;
	}
}

