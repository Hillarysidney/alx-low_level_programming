#include "main.h"

/**
 * _atoi - converts the string to an integer.
 * @s: params
 * Return: something
 */
int _atoi(char *s)
{
	unsigned int begin = 0, size = 0, h = 0, v = 1, m = 1, i;

	while (*(s + begin) != '\0')
	{
		if (size > 0 && (*(s + begin) < '0' || *(s + begin) > '9'))
			break;

		if (*(s + begin) == '-')
			v *= -1;

		if ((*(s + begin) >= '0') && (*(s + begin) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		begin++;
	}

	for (i = begin - size; i < begin; i++)
	{
		h = h + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (h * v);
}
