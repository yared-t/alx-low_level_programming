#include "lists.h"
/**
 * add_nodeint - program used to write a function that adds a new node
 * @n: used to store number
 * @head: used to store head
 * Return: the address new element
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}

