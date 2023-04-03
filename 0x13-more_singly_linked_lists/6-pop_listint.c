#include "lists.h"

/**
 * pop_listint - program used to deletes the head node
 * @head: used to store the head
 * Return: 0
 */
int pop_listint(listint_t **head)
{
	listint_t *t;
	int c;

	if (!head || !*head)
		return (0);
	c = (*head)->n;
	t = (*head)->next;
	free(*head);
	*head = t;
	return (c);
}


