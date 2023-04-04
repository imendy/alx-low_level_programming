#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index
 * @head: the double pointer
 * @index: index of node
 *
 * Return: pointer to the index node
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int j;
	listint_t *temp, *next;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
		return (1);
	}
	temp = *head;
	for (j = 0; j < index - 1; j++)
	{
		if (temp->next == NULL)
			return (-1);
		temp = temp->next;
	}
	next = temp->next;
	temp->next = next->next;
	free(next);
	return (1);

}
