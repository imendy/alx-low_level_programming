#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserting a new node at agiven postion
 * @head: the double pointer
 * @idx: the index of the node
 * @n: new node value
 *
 * Return: the address of the new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int j;
	listint_t *temp, *newPtr;

	if (head == NULL)
		return (NULL);
	if (idx != 0)
	{
		temp = *head;
		for (j = 0; j < idx - 1 && temp != NULL; j++)
		{
			temp = temp->next;
		}
		if (temp == NULL)
			return (NULL);
	}
	newPtr = malloc(sizeof(listint_t));
	if (newPtr == NULL)
		return (NULL);
	newPtr->n = n;
	if (idx == 0)
	{
		newPtr->next = *head;
		*head = newPtr;
		return (newPtr);
	}
	newPtr->next = temp->next;
	temp->next = newPtr;
	return (newPtr);
}
