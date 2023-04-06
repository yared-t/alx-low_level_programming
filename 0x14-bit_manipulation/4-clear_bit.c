#include "main.h"

/**
 * clear_bit - used to clear bots
 * @n: used to store n
 * @index: used to store the index
 * Return: 1 or 0
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
