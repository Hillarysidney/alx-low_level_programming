#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *noded, *tmpest;
	unsigned long int ob;

	for (ob = 0; ob < ht->size; ob++)
	{
		if (ht->array[ob] != NULL)
		{
			noded = ht->array[ob];
			while (noded != NULL)
			{
				tmpest = noded->next;
				free(noded->key);
				free(noded->value);
				free(noded);
				noded = tmpest;
			}
		}
	}
	free(head->array);
	free(head);
}
