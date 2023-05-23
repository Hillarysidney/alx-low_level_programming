#include "main.h"
/**
 *_memset -   fills memory with the constant byte
 *@s: pointer block of the memory to fill
 *@b: value to set
 *@n: bytes of memory
 *Return: dest
 */

char *_memset(char *s, char b, unsigned int n)

{
	unsigned int o;

	/*Delacring FOR*/
	for (o = 0; o < n; o++)
	{
		*(s + o) = b; /*add 1 position s*/

	} /*END FOR*/

	return (s);
}
