#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct number - struct represents a numerical value with
 * additional information about its sign and size.
 * @array: array of integers that store digits of the number
 * @size: size of the array
 * @sign: sign of the number
 *
 * Description: The number struct is a data structure designed to represent
 * a numerical value along with additional information about its sign and size
 */
typedef struct number
{
	int *array;
	int size;
	int sign;
} number;

typedef int (*FuncPtr)(int);
typedef int (*StrPtr)(char *);
typedef int (*UnPtr)(size_t);

/**
 * struct print_d - represents a format specifier and a corresponding function
 * pointer
 * @specifier: format specifier
 * @function: function pointer
 *
 * Desription: The print_d struct is a data structure designed to represent
 * and associate a format specifier with its corresponding function pointer.
 */
typedef struct print_d
{
	char specifier;
	FuncPtr function;
} SpecifierInfo;

/**
 * struct print_u - represents a format specifier and a corresponding
 * function pointer
 * @s: format specifier
 * @u: function pointer
 *
 * Description: The print_u struct is a data structure designed to encapsulate
 * and associate a format specifier and its corresponding function pointer.
 */
typedef struct print_u
{
	char s;
	UnPtr u;
} print_u;

int _puts(char *str);
int _putchar(int c);
int print_num(int n);
number parse_num(int n);
int _printf(const char *format, ...);
StrPtr CheckStrSpecifier(char s);
FuncPtr CheckIntSpecifier(char c);
int print_int(int n);
int print_bin(size_t n);
number parse_bin(size_t n);
int print_un(size_t n);
number parse_un(size_t n);
UnPtr CheckUnSpecifier(char c);
int ChoSpecFunc(char c, va_list args);
void builtin_exec(char **line, int actual_case);

#endif

