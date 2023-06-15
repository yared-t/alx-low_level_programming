#include "lists.h"

/**
 * dlistint_len - progrma used to count
 * @h: used to store a nodre
 * Return: success
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}

	return (count);
}
