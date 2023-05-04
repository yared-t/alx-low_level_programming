#include "main.h"
/**
 * flip_bits - progrma used to flip bits
 * @n: used to store the unsigned int
 * @m: used to store the unsigned int
 * Return: the flipbits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, c = 0;
	unsigned long int new, old = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		new = old >> x;
		if (new & 1)
			c++;
	}

	return (c);
}

