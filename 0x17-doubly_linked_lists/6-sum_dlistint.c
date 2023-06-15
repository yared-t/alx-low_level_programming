#include "lists.h"

/**
 * sum_dlistint - progrma used to store the data
 * @head: used to store the head
 * Return: success
 */
int sum_dlistint(dlistint_t *head)
{
	size_t res = 0;

	if (head == NULL)
		return (0);

	while (head != NULL)
	{
		res += head->n;
		head = head->next;
	}

	return (res);
}

