#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node in a dlistint_t
 *                            list at a given position.
 * @h: A pointer to the head of the dlistint_t list.
 * @idx: The position to insert the new node.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp_ptr = *h, *the_new_node;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		temp_ptr = temp_ptr->next;
		if (temp_ptr == NULL)
			return (NULL);
	}

	if (temp_ptr->next == NULL)
		return (add_dnodeint_end(h, n));

	the_new_node = malloc(sizeof(dlistint_t));
	if (the_new_node == NULL)
		return (NULL);

	the_new_node->n = n;
	the_new_node->prev = temp_ptr;
	the_new_node->next = temp_ptr->next;
	temp_ptr->next->prev = the_new_node;
	temp_ptr->next = the_new_node;

	return (the_new_node);
}
