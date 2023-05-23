#include "main.h"
/**
 *_strncat - concatenates the two strings
 *@dest: A pointer to the character that will be changed
 *@src: A pointer to the character that will be changed
 *@n: value
 *Return: dest
 */

char *_strncat(char *dest, char *src, int n)

{
int o, h;

o = 0;
while (dest[o] != '\0')
{
o++;
}

h = 0;
while (h < n && src[h] != '\0')
{
dest[o] = src[h];
h++;
o++;
}

dest[o] = '\0';

return (dest);
}
