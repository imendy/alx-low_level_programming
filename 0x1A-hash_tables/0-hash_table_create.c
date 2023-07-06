#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the hash table
 *
 * Return: pointer to hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *the_table;

	if (size == 0)
		return (NULL);

	the_table = calloc(1, sizeof(hash_table_t));
	if (the_table == NULL)
		return (NULL);

	the_table->size = size;
	the_table->array = calloc(size, sizeof(hash_node_t *));
	if (the_table->array == NULL)
	{
		free(the_table);
		return (NULL);
	}
	return (the_table);
}
