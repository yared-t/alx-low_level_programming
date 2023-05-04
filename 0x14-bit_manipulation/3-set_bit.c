#include "main.h"

/**
 * set_bit - program used to set a bit
 * @n: used to store the unsigned long
 * @index: used to store the unsigned index
 * Return: success
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}

