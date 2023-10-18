#include "main.h"

/**
 * parse_num - parses number into an array of its digits
 * @n: input number
 *
 * Return: returns a struct number, otherwise NULL.
 */
number parse_num(int n)
{
	number num;
	int result = 0;
	int temp;
	int *buffer;

	num.size = 0;
	num.sign = 0;

	if (n < 0)
	{
		num.sign = 1;
		n *= -1;
	}

	/* Calculate the number of digits in n */
	temp = n;
	while (temp)
	{
		temp /= 10;
		num.size++;
	}

	/* Allocate memory for int array and check success */
	num.array = malloc(sizeof(int) * num.size);
	if (num.array == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	buffer = num.array;
	while (n != 0)
	{
		result = n % 10;
		*buffer = result;
		n /= 10;
		buffer++;
	}
	return (num);
}

/**
 * print_num - prints a signed number
 * @n: input number
 * Return: returns number of characters printed, 0 otherwise.
 */
int print_num(int n)
{
	number num = parse_num(n);
	int i, len = num.size;

	if (num.array == NULL)
		return (0);

	if (num.sign == 1)
	{
		_putchar('-');
		len++;
	}
	for (i = num.size - 1; i >= 0; i--)
		_putchar(num.array[i] + '0');
	free(num.array);
	return (len);
}

/**
 * print_int - print a signed integer
 * @n: integer
 * Return: number of characters printed
 */
int print_int(int n)
{
	return (print_num(n));
}
