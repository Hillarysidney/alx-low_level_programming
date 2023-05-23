#include "main.h"

/**
 * _strspn - Locates the character in a string
 * @s: This is a main C string to be scanned.
 * @accept: This is a string containing the list of characters to match in s
 * Return: return begin
 **/

unsigned int _strspn(char *s, char *accept)

{
	int o, h;
	int begin = 0;
	char *str4, *str5;

	str4 = s;
	str5 = accept;

	o = 0;
	while (str4[o] != '\0') /*Declaring WHILE *s */
	{
		h = 0;
		while (str5[h] != '\0') /*Declaring WHILE *accept*/
		{
			if (str5[h] == str4[o]) /*Evaluate condition*/
			{
				begin++; /*begin number*/
				break;
			}

			h++;    /*add h+1*/
		}

		if (s[o] != accept[h]) /*If aren'o equals*/
		{
			break;
		}

		o++; /*add x+1*/
	}

	return (begin); /*return the value of begin*/
}
