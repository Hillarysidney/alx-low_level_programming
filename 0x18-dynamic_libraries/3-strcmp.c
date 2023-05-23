#include "main.h"
/**
 *_strcmp - compares the two strings
 *@s1: A pointer to the character that will be changed
 *@s2: A pointer to the character that will also be changed/updated/modified
 *Return: dest
 */

int _strcmp(char *s1, char *s2)

{

char *str_first = s1;
char *str_second = s2;


while (*str_first != '\0' && *str_second != '\0' && *str_first == *str_second)
{
str_first++;
str_second++;
}

return (*str_first - *str_second);
}
