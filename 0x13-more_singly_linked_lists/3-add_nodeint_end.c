#include "lists.h"
#include <stdlib.h>
/**
  * add_nodeint_end - add node at end of a listint_t list.
  *
  * @head: head of a double pointer
  * @n: int add the list
  * Return: NULL if it fails
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newPtr;
	listint_t *temp;

	if (head == NULL)
		return (NULL);
	newPtr = malloc(sizeof(listint_t));
	if (newPtr == NULL)
		return (NULL);
	newPtr->n = n;
	newPtr->next = NULL;
	if (*head == NULL)
	{
	*head = newPtr;
		return (newPtr);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newPtr;
	return (newPtr);
}
