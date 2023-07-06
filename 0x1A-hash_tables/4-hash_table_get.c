#include "hash_tables.h"
/**
 * hash_table_get - function to retrieve value associeted with key
 * @ht: pointer to hash table
 * @key: key to retrive value
 *
 * Return: value or NULL if key does not exit.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t  *the_cup;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	the_cup = ht->array[index];

	while (the_cup)
	{
		if (!strcmp(key, the_cup->key))
			return (the_cup->value);
		the_cup = the_cup->next;
	}
	return (NULL);
}
