#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			result = result * 10 + (*s - '0');
		else if (result > 0)  /* stop if we encounter non-digit after digits */
			break;
		s++;
	}

	return (result * sign);
}


/**
 * is_valid_arg - checks if an arg is valid
 * @str: arg string
 *
 * Return: returns 0 id arg is valid, 0 otherwise.
 */
int is_valid_arg(char *str)
{
	int i = 0, arg;
	char *s = str;

	while (str[i])
	{
		if (_isdigit(str[i]) != 1)
			return (1);
		i++;
	}
	arg = _atoi(s);
	if (arg < 0)
		return (1);
	return (0);
}

/**
 * _isdigit - checks if a character is a digit
 *
 * @c: the character to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
