#include "hash_tables.h"

/**
 * hash_table_print - function to print the key:value from ht
 * @ht: pointer to hash table
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int k = 0;
	hash_node_t  *the_cup;
	int the_nut = 0;

	if (!ht)
		return;

	printf("{");
	for (k = 0; k < ht->size; k++)
	{
		the_cup = ht->array[k];
		while (the_cup)
		{
			if (the_nut)
				printf(", ");
			printf("'%s': '%s'", the_cup->key, the_cup->value);
			the_nut = 1;
			the_cup = the_cup->next;
		}
	}
	printf("}\n");
}
