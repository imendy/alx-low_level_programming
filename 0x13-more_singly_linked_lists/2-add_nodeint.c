#include "lists.h"
#include <stdlib.h>
/**
  * add_nodeint - add node at beginning of a listint_t list.
  *
  * @head: head of a double pointer
  * @n: int add the list
  * Return: NULL if it fails
  */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newPtr;

	if (head == NULL)
		return (NULL);
	newPtr = malloc(sizeof(listint_t));
	if (newPtr == NULL)
		return (NULL);
	newPtr->n = n;
	newPtr->next = *head;
	*head = newPtr;
	return (newPtr);
}
