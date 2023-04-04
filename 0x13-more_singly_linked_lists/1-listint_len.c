#include "lists.h"
/**
 * listint_len - prints the number of elements
 * @h: used to store the linked list
 * Return: the number
 */
size_t listint_len(const listint_t *h)
{
	int c = 0;

	while (h)
	{
		c++;
		h = h->next;
	}
	return (c);
}
