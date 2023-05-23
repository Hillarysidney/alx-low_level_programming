#include "main.h"

/**
 * _strstr - first occurrence of a substring needle in a string haystack
 * @haystack: main str to be examined
 * @needle: searched in haystack
 * Return: return 0
 **/

char  *_strstr(char *haystack, char *needle)
{
	char *str4, *str5; /*Declaring variables*/

	while (*haystack != '\0')
	{
		str4 = haystack; /*values*/
		str5 = needle;

		/*Star WHILE*/
		while (*haystack != '\0' && *str5 != '\0' && *haystack == *str5)
		{
			haystack++;
			str5++;
		}
		if (*str5 == '\0')
			return (str4);
		haystack = str4 + 1;
	}
	return (0);
}
