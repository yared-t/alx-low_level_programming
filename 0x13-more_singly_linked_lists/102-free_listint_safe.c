#include "lists.h"

/**
 * free_listint_safe - program used to free listint
 * @h: used to store h
 * Return: NULL
 */
size_t free_listint_safe(listint_t **h)
{
	liatint_t *current = *h, *temp;
	size_t count = 0;

	while (current != NULL)
	{
		count++;
		temp = current;
		current = current->next;
		free(temp);
		if (*current == *h)
		{
			*h = NULL;
			break;
		}
	}
	return (count);
}


