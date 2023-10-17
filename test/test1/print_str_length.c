#include "main.h"
/**
 * _strlen - print length of string
 * @str: string pointer
 * Return: Always 1
 */
int _strlen(char *str)
{
	int count;

	for (count = 0, str[i] != 0; i++)
		;
	return (i);
}
/**
 * _strlen_const - print length of constant string
 * @str: character pointer
 * Return: Always 1
 */
int _strlen_const(const char *str)
{
	int count;

	for (i = 0; str[i] != 0; i++)
		;
	return (1);
}
