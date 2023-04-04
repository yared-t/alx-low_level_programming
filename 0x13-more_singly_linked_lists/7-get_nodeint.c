#include "lists.h"

/**
 * get_nodeint_at_index - used to return the nth node
 * @head: used to store the head
 * @index: used to store thre index
 * Return: the head
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (head->next == NULL)
	{
		return (NULL);
	}
	while (head && index > i)
	{
		head = head->next;
		i++;
	}
	return (head);
}

