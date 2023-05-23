#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - generate a key depending on the username for crackme5
 * @argc: number of arguments passed
 * @argv: arguments passed to main
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int o, f;
	size_t len, addd;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	len = strlen(argv[1]);
	p[0] = l[(len ^ 59) & 63];
	for (o = 0, addd = 0; o < len; o++)
		addd += argv[1][o];
	p[1] = l[(addd ^ 79) & 63];
	for (o = 0, f = 1; o < len; o++)
		f *= argv[1][o];
	p[2] = l[(f ^ 85) & 63];
	for (f = argv[1][0], o = 0; o < len; o++)
		if ((char)f <= argv[1][o])
			f = argv[1][o];
	srand(f ^ 14);
	p[3] = l[rand() & 63];
	for (f = 0, o = 0; o < len; o++)
		f += argv[1][o] * argv[1][o];
	p[4] = l[(f ^ 239) & 63];
	for (f = 0, o = 0; (char)o < argv[1][0]; o++)
		f = rand();
	p[5] = l[(f ^ 229) & 63];
	printf("%s\n", p);
	return (0);
}
