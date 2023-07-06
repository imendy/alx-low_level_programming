#include "hash_tables.h"

/**
 * hash_table_delete - free hash table and all nodes
 * @ht: pointer to hash table
 *
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *the_cup, *the_af;
	unsigned long int k = 0;

	if (!ht)
		return;

	for (k = 0; k < ht->size; k++)
	{
		the_cup = ht->array[k];
		while (the_cup)
		{
			the_af = the_cup;
			the_cup = the_cup->next;
			if (the_af->key)
				free(the_af->key);
			if (the_af->value)
				free(the_af->value);
			free(the_af);
		}
	}
	free(ht->array);
	free(ht);
}
