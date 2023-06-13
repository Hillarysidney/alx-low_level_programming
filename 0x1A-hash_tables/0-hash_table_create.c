#include "hash_tables.h"

/**
 * A hash_table_create - To Creates a hash table.
 * @size: The of size of the array.
 *
 * Return: If a error occurs - NULL.
 *         Otherwise - a pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ft;
	unsigned long int t;

	ft = malloc(sizeof(hash_table_t));
	if (ft == NULL)
		return (NULL);

	ft->size = size;
	ft->array = malloc(sizeof(hash_node_t *) * size);
	if (ft->array == NULL)
		return (NULL);
	for (t = 0; t < size; t++)
		ft->array[t] = NULL;

	return (ft);
}
