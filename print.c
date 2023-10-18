#include "main.h"

/**
 * _putchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * _puts - prints input string followed by a newline to output
 * @str: input string
 *
 * Return: the number of characters printed.
 */
int _puts(char *str)
{
	int string_length = 0;

	if (str == NULL)
		return (0);

	while (str[string_length] != '\0')
	{
		_putchar(str[string_length]);
		string_length++;
	}
	return (string_length);
}
