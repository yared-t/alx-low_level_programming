#include "lists.h"

/**
 * delete_nodeint_at_index - program used to delete
 * @head: used to store the head
 * @index: used to store the index
 * Return: 1 if successful -1 if faild
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *t;
	listint_t *new;

	t = *head;
	new = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		free(t);
		return (1);
	}
	for (i = 0; i < index -1; i++)
	{
		if (t == NULL && (t->next) == NULL)
		{
			return (-1);
		}
		t = t->next;
	}
	new = t->next;
	t->next = new->next;
	free(new);
	return (-1);
}
