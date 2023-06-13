#include "hash_tables.h"

/**
 * hash_table_get - Retrieve value associated with
 *                  a key in a hash table.
 * @ht: A pointer to hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *noded;
	unsigned long int idxes;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idxes = key_index((const unsigned char *)key, ht->size);
	if (idxes >= ht->size)
		return (NULL);

	noded = ht->array[idxes];
	while (noded && strcmp(noded->key, key) != 0)
		noded = noded->next;

	return ((noded == NULL) ? NULL : noded->value);
