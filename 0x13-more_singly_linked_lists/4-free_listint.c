#include "lists.h"

/**
 * free_listint - used to frees a listint list
 * @head: used to store the head
 */
void free_listint(listint_t *head)
{
	listint_t *t;

	while (head)
	{
		t = head->next;
		free(head);
		head = t;
	}
}

