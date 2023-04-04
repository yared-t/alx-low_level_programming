#include "lists.h"

/**
 * free_listint_safe - program used to free listint
 * @h: used to store h
 * Return: NULL
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h, *temp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);
	while (current != NULL)
	{
		count++;
		if (current <= current->next)
		{
			*h = NULL;
			free(current);
			break;
		}
		temp = current;
		current = current->next;
		free(temp);
	}
	return (count);
}


