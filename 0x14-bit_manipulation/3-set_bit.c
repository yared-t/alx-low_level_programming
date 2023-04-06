#include "main.h"

/**
 * set_bit - programs set values
 * @n: used to store the number
 * @index: used to store the index
 * Return: 1 or -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	*n = (*n | (1 << index));
	return (1);
}
