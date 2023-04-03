#include "lists.h"
/**
 * print_listint - program used to print all the elements of lists
 * @h: used to store list
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	int c = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		c++;
	}
	return (c);
}


