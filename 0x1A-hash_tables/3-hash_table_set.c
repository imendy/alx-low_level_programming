#include "hash_tables.h"

/**
 * hash_table_set - adds item in a hash table
 * @ht: the table
 * @key: key of the item
 * @value: value of the item
 * Return: 1 for success 0 for failure
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int k;
	hash_node_t *the_new, *my_tmp;

	if (!ht || !key || !(*key))
		return (0);
	the_new = malloc(sizeof(*the_new));
	if (!thenew)
		return (0);
	the_new->key = strdup((char *)key);
	the_new->value = strdup(value);
	the_new->next = NULL;
	k = key_index((unsigned char *)key, ht->size);
	if (!(ht->array[k]))
	{
		ht->array[k] = the_new;
	}
	else
	{
		/* check for update */
		my_tmp = ht->array[k];
		while (my_tmp && strcmp(my_tmp->key, the_new->key) != 0)
			my_tmp = my_tmp->next;
		if (my_tmp) /* its update */
		{
			free(my_tmp->value);
			my_tmp->value = the_new->value;
			free(the_new->key);
			free(the_new);
			return (1);
		}
		/* its a collision */
		my_tmp = ht->array[k];
		the_new->next = my_tmp;
		ht->array[k] = the_new;
	}

	return (1);
}
