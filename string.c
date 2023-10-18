#include "shell.h"

/**
 * _strlen - computes length of input string
 * @s: input string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: returns 0 if the strings match, and -1 otherwise.
 */
int _strcmp(char *s1, char *s2)
{
	int status = -1;

	if (strlen(s1) != strlen(s2))
		return (status);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
		{
			status = -1;
			break;
		}
		else
			status = 0;
		s1++;
		s2++;
	}
	return (status);
}

/**
 * _strcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: returns a pointer to a dynamically allocated
 * memory containing the concatenated string, otherwise NULL.
 */
char *_strcat(char *s1, char *s2)
{
	int i = 0;
	char *cat_str = malloc(strlen(s1) + strlen(s2) + 1);

	if (!s1 || !s2 || !cat_str)
		return (NULL);

	while (*s1)
	{
		cat_str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		cat_str[i] = *s2;
		i++;
		s2++;
	}

	cat_str[i] = '\0';
	return (cat_str);
}

/**
 * _strcpy - Copies string pointed to by src to buffer pointed to by dest
 * @dest: Destination memory block
 * @src: Source memory block
 * Return: return dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * *_strdup - duplicates input string
 * @str: input string
 *
 * Return: pointer to a dynamically allocated
 * memory containing the duplicate string.
 */
char *_strdup(char *str)
{
	char *s;
	unsigned int size;

	if (str == NULL)
		return (NULL);
	size = _strlen(str) + 1;
	/*Allocate dynamic meemory to array*/
	s = (char *)malloc(size);

	/*Condition for unsuccessful allocation*/
	if (s == NULL)
		return (NULL);

	/*Copy contents of str into s*/
	return (_strcpy(s, str));
}
