#include "main.h"
/**
 * _puts - pusts to the stdout
 * @str: params
 */

void _puts(char *str)
{
	int o = 0;

	while (str[o] != '\0')
	{
		_putchar(str[o]);
		o++;
	}

	_putchar('\n');
}
