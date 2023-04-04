#include "lists.h"

/**
 * print_listint_safe- p=ogram used to prints listint_t
 * @head: used to store the head
 * Return: NULL
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0;

	while (fast != NULL && fast->next != NULL)
	{
		printf("%p %d\n", (void*)slow, slow->n);
		count++;
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			printf("%p %d\n",(void*)slow, slow->n);
			count++;
			break;
		}
	}
	if (fast == NULL || fast->next == NULL)
	{
		while (slow != NULL)
		{
			printf("%p %d\n", (void*)slow, slow->n);
			count++;
			slow = slow->next;
		}
	}
	if (count == 0)
	{
		exit(98);
	}
	return (count);
}



