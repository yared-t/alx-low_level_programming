#include "lists.h"

/**
 * reverse_listint - used to reverse alist
 * @head: used to strore the head
 * Return: NULL
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *old = NULL;
	listint_t *new = NULL;

	while (*head != NULL)
	{
		new = (*head)->next;
		(*head)->next = old;
		old = *head;
		*head = new;
	}
	*head = old;
	return (*head);
}


