#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the hash table
 *
 * Return: pointer to the new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *the_s;
	unsigned long int k;

	the_s = malloc(sizeof(shash_table_t));
	if (the_s == NULL)
		return (NULL);
	the_s->size = size;
	the_s->shead = NULL;
	the_s->stail = NULL;
	the_s->array = malloc(sizeof(shash_node_t) * size);
	if (the_s->array == NULL)
	{
		free(the_s);
		return (NULL);
	}
	for (k = 0; k < size; k++)
	{
		the_s->array[k] = NULL;
	}
	return (the_s);
}

/**
 * make_shash_node - makes a node for the sorted hash table
 * @key: key for the data
 * @value: data to be stored
 *
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *the_n;

	the_n = malloc(sizeof(shash_node_t));
	if (the_n == NULL)
		return (NULL);
	the_n->key = strdup(key);
	if (the_n->key == NULL)
	{
		free(the_n);
		return (NULL);
	}
	the_n->value = strdup(value);
	if (the_n->value == NULL)
	{
		free(the_n->key);
		free(the_n);
		return (NULL);
	}
	the_n->next = the_n->snext = the_n->sprev = NULL;
	return (the_n);
}

/**
 * add_to_sorted_list - add a node to the sorted (by key's ASCII) linked list
 * @table: the sorted hash table
 * @node: the node to add
 *
 * Return: void
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *the_p;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	the_p = table->shead;
	while (the_p != NULL)
	{
		if (strcmp(node->key, the_p->key) < 0)
		{
			node->snext = the_p;
			node->sprev = the_p->sprev;
			the_p->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		the_p = the_p->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: sorted hash table
 * @key: key to the data
 * @value: data to add
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int the_idx;
	char *the_value;
	shash_node_t *the_n, *the_p;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	the_idx = key_index((const unsigned char *)key, ht->size);
	the_p = ht->array[the_idx];
	while (the_p != NULL)
	{
		if (strcmp(the_p->key, key) == 0)
		{
			the_value = strdup(value);
			if (the_value == NULL)
				return (0);
			free(the_p->value);
			the_p->value = the_value;
			return (1);
		}
		the_p = the_p->next;
	}
	the_n = make_shash_node(key, value);
	if (the_n == NULL)
		return (0);
	the_n->next = ht->array[the_idx];
	ht->array[the_idx] = the_n;
	add_to_sorted_list(ht, the_n);
	return (1);
}

/**
 * shash_table_get - retrieve a value from the hash table
 * @ht: hash table
 * @key: key to the data
 *
 * Return: the value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int the_idx;
	shash_node_t *the_p;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	the_idx = key_index((const unsigned char *)key, ht->size);
	the_p = ht->array[the_idx];
	while (the_p != NULL)
	{
		if (strcmp(the_p->key, key) == 0)
			return (the_p->value);
		the_p = the_p->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *the_p;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	the_p = ht->shead;
	while (the_p != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", the_p->key, the_p->value);
		flag = 1;
		the_p = the_p->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *the_p;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	the_p = ht->stail;
	while (the_p != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", the_p->key, the_p->value);
		flag = 1;
		the_p = the_p->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int k;
	shash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (k = 0; k < ht->size; k++)
	{
		while (ht->array[k] != NULL)
		{
			next = ht->array[k]->next;
			free(ht->array[k]->key);
			free(ht->array[k]->value);
			free(ht->array[k]);
			ht->array[k] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
