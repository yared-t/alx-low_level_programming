#include "lists.h"

/**
 * print_dlistint - program used to print list int
 * @h:used to store nofr
 * Return: succrdd
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}

