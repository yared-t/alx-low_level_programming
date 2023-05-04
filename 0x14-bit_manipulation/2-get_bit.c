#include "main.h"
/**
 * get_bit - program used to get the bit
 * @n: used to store the long int
 * @index: used to store the unsigned int
 * Return: the value
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int v;

	if (index > 63)
		return (-1);

	v = (n >> index) & 1;

	return (v);
}

