#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - function that frees a listint_t list
 * @head: a double pointer of the lists
 *
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *newNext;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		newNext = (*head)->next;
		free(*head);
		*head = newNext;
	}
}
