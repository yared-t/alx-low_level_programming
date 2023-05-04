#include "main.h"
/**
 * binary_to_uint - program used to display int
 * @b: used to store the binary
 * Return: intiger for success
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int v = 0;
	int n;

	if (!b)
		return (0);

	for (n = 0; b[n]; n++)
	{
		if (b[n] < '0' || b[n] > '1')
			return (0);
		v = 2 * v + (b[n] - '0');
	}

	return (v);
}

