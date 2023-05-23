#include "main.h"
/**
 *_strcat - concatenate two strings
 *@dest: A pointer to the character that will be changed
 *@src: A pointer to the character that will also be changed
 *Return: dest
 */

char *_strcat(char *dest, char *src)
{
int o, h;

o = 0;
while (dest[o] != '\0')
{
o++;
}

h = 0;
while (src[h] != '\0')
{
dest[o] = src[h];
h++;
o++;
}
dest[o] = '\0';

return (dest);
}
