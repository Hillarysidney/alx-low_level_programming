#include "main.h"
/**
 * _strlen - string lenght
 * @s: params
 * Return: int
 */

int _strlen(char *s)
{
	int begin = 0;

	while (s[begin] != '\0')
	{
		begin++;
	}

	return (begin);
}
