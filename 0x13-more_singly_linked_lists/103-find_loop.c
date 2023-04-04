#include "lists.h"

/**
 * find_listint_loop - prints loop
 * @head: stores head
 * Return: NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (!head || !head->next)
		return (NULL);
	slow = head->next;
	fast = head->next->next;
	while (fast && fast->next)
	{
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return (NULL);
}



