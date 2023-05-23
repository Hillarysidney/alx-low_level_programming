#include "main.h"
/**
 *_strncpy - copies a string
 *@dest: A pointer to the character that will be changed
 *@src: A pointer to the character that will be changed
 *@n: value
 *Return: dest
 */

char *_strncpy(char *dest, char *src, int n)

{
int o;

o = 0;
while (o < n && src[o] != '\0')
{
dest[o] = src[o];
o++;
}

while (o < n)
{
dest[o] = '\0';
o++;
}

return (dest);

}
