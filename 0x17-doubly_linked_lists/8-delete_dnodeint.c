#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node from a dlistint_t
 *                            at a given index.
 * @head: A pointer to the head of the dlistint_t.
 * @index: The index of the node to delete.
 *
 * Return: Upon success - 1.
 *         Otherwise - -1.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp_ptr = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (temp_ptr == NULL)
			return (-1);
		temp_ptr = temp_ptr->next;
	}

	if (temp_ptr == *head)
	{
		*head = temp_ptr->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		temp_ptr->prev->next = temp_ptr->next;
		if (temp_ptr->next != NULL)
			temp_ptr->next->prev = temp_ptr->prev;
	}

	free(temp_ptr);
	return (1);
}
