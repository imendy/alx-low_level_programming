#include "lists.h"

/**
 * dlistint_len - Counts the number of elements in a linked dlistint_t list.
 * @h: The head of the dlistint_t list.
 *
 * Return: The number of elements in the dlistint_t list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t my_nodes = 0;

	while (h)
	{
		my_nodes++;
		h = h->next;
	}

	return (my_nodes);
}
