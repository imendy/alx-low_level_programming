#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: A pointer to the head of the dlistint_t list.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *the_new_node, *the_last_node;

	the_new_node = malloc(sizeof(dlistint_t));
	if (the_new_node == NULL)
		return (NULL);

	the_new_node->n = n;
	the_new_node->next = NULL;

	if (*head == NULL)
	{
		the_new_node->prev = NULL;
		*head = the_new_node;
		return (the_new_node);
	}

	the_last_node = *head;
	while (the_last_node->next != NULL)
		the_last_node = the_last_node->next;
	the_last_node->next = the_new_node;
	the_new_node->prev = the_last_node;

	return (the_new_node);
}
