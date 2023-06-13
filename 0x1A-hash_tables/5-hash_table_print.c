#include "hash_tables.h"

/**
 * hash_table_print - Prints hash table.
 * @ht: A pointer to hash table to print.
 *
 * Description: Key/value pairs are printed in the order
 *              they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *noded;
	unsigned long int ob;
	unsigned char comand_flaged = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (ob = 0; ob < ht->size; ob++)
	{
		if (ht->array[ob] != NULL)
		{
			if (comand_flaged == 1)
				printf(", ");

			noded = ht->array[ob];
			while (noded != NULL)
			{
				printf("'%s': '%s'", noded->key, noded->value);
				noded = noded->next;
				if (noded != NULL)
					printf(", ");
			}
			comand_flaged = 1;
		}
	}
	printf("}\n");
}
