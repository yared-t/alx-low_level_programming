#include "lists.h"

/**
 * free_dlistint - progrma used to dlist in
 * @head: store the head data
 * Return: success
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp_node = NULL;

	while (head != NULL)
	{
		temp_node = head->next;
		free(head);
		head = temp_node;
	}
}

