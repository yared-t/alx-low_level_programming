#include "lists.h"

/**
 * add_nodeint_end - progarm used to add new node
 * @head: used to store the head
 * @n: used to store the number
 * Return: the address or NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node;
	listint_t *t;

	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;

	t = *head;
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	while (t->next)
		t = t->next;
	t->next = node;
	return (node);
}
