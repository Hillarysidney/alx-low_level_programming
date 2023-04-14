#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and print
 * 0 when funtion fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fk;
	ssize_t z;
	ssize_t f;

	fk = open(filename, O_RDONLY);
	if (fk == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	f = read(fk, buf, letters);
	z = write(STDOUT_FILENO, buf, f);

	free(buf);
	close(fk);
	return (z);
}
