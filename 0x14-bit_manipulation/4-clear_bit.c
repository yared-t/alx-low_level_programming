#include "main.h"

/**
 * clear_bit - program used to clearbit
 * @n: used to store the int
 * @index: used to store the index to be clear
 * Return: 1 or -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

