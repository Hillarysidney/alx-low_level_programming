#include "main.h"

/**
 * _strpbrk - matches any character that is specified
 * @s: This is the C string to be scanned.
 * @accept:character in str1 that matches one of a characters in str2
 *Return: string s that matches any character specified in accept
 **/

char *_strpbrk(char *s, char *accept)
{
	int h;

	while (*s != '\0') /*Declaring WHILE*/
	{
		h = 0;
		while (accept[h] != '\0')  /*Evaluating *accept*/
		{
			if (*s == accept[h])
			{
				return (s);
			}

			h++; /*add h+1*/
		}

		s++; /*add s+1*/
	}
	return (0);

}
