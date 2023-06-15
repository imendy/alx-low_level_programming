#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 * @head: A pointer to the head of the dlistint_t list.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *the_new;

	the_new = malloc(sizeof(dlistint_t));
	if (the_new == NULL)
		return (NULL);

	the_new->n = n;
	the_new->prev = NULL;
	the_new->next = *head;
	if (*head != NULL)
		(*head)->prev = the_new;
	*head = the_new;

	return (the_new);
}
