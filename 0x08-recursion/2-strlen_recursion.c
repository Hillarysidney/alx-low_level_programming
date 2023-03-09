#include "main.h"
/**
 * _strlen_recursion - Returns the length of a string.
 *
 * Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
	int longit = 0;

	if (*s)
	{
		longit++;
		long += _strlen_recursion(s + 1);
	}

	return (longit);
}
