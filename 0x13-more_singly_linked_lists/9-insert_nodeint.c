#include "lists.h"

/**
 * insert_nodeint_at_index - used to insert a value to a node
 * @head: used to store the head
 * @idx: used to store the index
 * @n: the store value
 * Return: NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int c = 0;
	listint_t *t;
	listint_t *new;

	if (*head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	t = *head;
	for (c = 0; c < idx; c++)
	{
		if (c == idx - 1)
		{
			new->n = n;
			new->next = t->next;
			t->next = new;
			return (new);
		}
	}
	return (NULL);
}
