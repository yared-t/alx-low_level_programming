#include "lists.h"

/**
 * get_dnodeint_at_index - program used index a node
 * @head: used to store the head
 * @index: used to store the index
 * Return: success
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	size_t count = 0;

	while (head != NULL)
	{
		if (count == index)
			break;
		count++;
		head = head->next;
	}

	return (head);
}

