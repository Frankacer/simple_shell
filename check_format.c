#include "main.h"

/**
 * CheckIntSpecifier - checks the format specifier and returns
 * the corresponding function pointer.
 * @c: The format specifier character
 *
 * Return: Pointer to the appropriate function; otherwise, NULL.
 */
FuncPtr CheckIntSpecifier(char c)
{
	int i;

	/* Initialize an array of specifier-function pairs */
	SpecifierInfo intSpecifiers[] = {
		{'c', _putchar},
		{'d', print_num},
		{'i', print_int},
		{'\0', NULL}
	};

	/* Iterate through the array to find a matching specifier */
	for (i = 0; intSpecifiers[i].specifier != '\0'; i++)
	{
		if (intSpecifiers[i].specifier == c)
			return (intSpecifiers[i].function);
	}

	return (NULL); /* Return NULL if no matching specifier is found */
}

/**
 * CheckStrSpecifier - checks the format specifier and returns
 * the corresponding function pointer.
 * @c: The format specifier character
 *
 * Return: Pointer to the appropriate function; otherwise, NULL.
 */
StrPtr CheckStrSpecifier(char c)
{
	if (c == 's')
		return (_puts);

	return (NULL); /* Return NULL for unsupported specifiers */
}

/**
 * ChoSpecFunc - Chooses and executes the appropriate function
 * based on the format specifier.
 * @c: The format specifier character
 * @args: The variable arguments list
 *
 * Return: The number of characters printed.
 */
int ChoSpecFunc(char c, va_list args)
{
	FuncPtr print_num = NULL;
	StrPtr print_str = NULL;
	int num, chars_printed = 0;
	char *str;

	/* Check for integer specifiers */
	print_num = CheckIntSpecifier(c);
	if (print_num != NULL)
	{
		num = va_arg(args, int);
		chars_printed += (print_num(num));
	}
	else
	{
		/* Check for string specifier */
		print_str = CheckStrSpecifier(c);
		if (print_str != NULL)
		{
			str = va_arg(args, char *);
			chars_printed += (print_str(str));
		}
	}

	return (chars_printed);
}

