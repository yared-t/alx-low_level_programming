#include "main.h"

/**
 * get_bit - used to return the value of bit
 * @n: used to store the number
 * @index: stores the index value
 * Return: value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}
	return ((n >> index) & 1);
}
