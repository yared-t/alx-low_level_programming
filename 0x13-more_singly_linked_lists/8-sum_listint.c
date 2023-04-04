#include "lists.h"

/**
 * sum_listint - used to store the sum
 * @head: used to store the head
 * Return: returns sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
