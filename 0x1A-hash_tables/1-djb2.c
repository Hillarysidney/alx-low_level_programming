#include "hash_tables.h"

/**
 * hash_djb2 - Hash function implementing the djb2 algorithm.
 * @str: The string to hashes.
 *
 * Return: The calculated hashes.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hashes;
	int o;

	hashes = 5381;
	while ((o = *str++))
		hashes = ((hashes << 5) + hashes) + o; /* hashes * 33 + o */

	return (hashes);
}
