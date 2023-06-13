#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in hash table.
 * @ht: A pointer to hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *fresh;
	char *value_copyied;
	unsigned long int idx, ob;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copyied = strdup(value);
	if (value_copyied == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	for (ob = idx; ht->array[ob]; ob++)
	{
		if (strcmp(ht->array[ob]->key, key) == 0)
		{
			free(ht->array[ob]->value);
			ht->array[ob]->value = value_copyied;
			return (1);
		}
	}

	fresh = malloc(sizeof(hash_node_t));
	if (fresh == NULL)
	{
		free(value_copyied);
		return (0);
	}
	fresh->key = strdup(key);
	if (fresh->key == NULL)
	{
		free(fresh);
		return (0);
	}
	fresh->value = value_copyied;
	fresh->next = ht->array[idx];
	ht->array[idx] = fresh;

	return (1);
}
