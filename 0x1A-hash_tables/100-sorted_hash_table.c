#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int ob;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (ob = 0; ob < size; ob++)
		ht->array[ob] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmpest;
	char *value_copyied;
	unsigned long int idxes;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copyied = strdup(value);
	if (value_copyied == NULL)
		return (0);

	idxes = key_index((const unsigned char *)key, ht->size);
	tmpest = ht->shead;
	while (tmpest)
	{
		if (strcmp(tmpest->key, key) == 0)
		{
			free(tmpest->value);
			tmpest->value = value_copyied;
			return (1);
		}
		tmpest = tmpest->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copyied);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copyied);
		free(new);
		return (0);
	}
	new->value = value_copyied;
	new->next = ht->array[idxes];
	ht->array[idxes] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmpest = ht->shead;
		while (tmpest->snext != NULL && strcmp(tmpest->snext->key, key) < 0)
			tmpest = tmpest->snext;
		new->sprev = tmpest;
		new->snext = tmpest->snext;
		if (tmpest->snext == NULL)
			ht->stail = new;
		else
			tmpest->snext->sprev = new;
		tmpest->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *noded;
	unsigned long int idxes;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idxes = key_index((const unsigned char *)key, ht->size);
	if (idxes >= ht->size)
		return (NULL);

	noded = ht->shead;
	while (noded != NULL && strcmp(noded->key, key) != 0)
		noded = noded->snext;

	return ((noded == NULL) ? NULL : noded->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *noded;

	if (ht == NULL)
		return;

	noded = ht->shead;
	printf("{");
	while (noded != NULL)
	{
		printf("'%s': '%s'", noded->key, noded->value);
		noded = noded->snext;
		if (noded != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *noded;

	if (ht == NULL)
		return;

	noded = ht->stail;
	printf("{");
	while (noded != NULL)
	{
		printf("'%s': '%s'", noded->key, noded->value);
		noded = noded->sprev;
		if (noded != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *noded, *tmpest;

	if (ht == NULL)
		return;

	noded = ht->shead;
	while (noded)
	{
		tmpest = noded->snext;
		free(noded->key);
		free(noded->value);
		free(noded);
		noded = tmpest;
	}

	free(head->array);
	free(head);
}
