#include "main.h"
/**
 * binary_to_uint - program used to convert binariy to usigned int
 * @c: used to store the char
 * Return: uint or null
 */
unsigned int binary_to_uint(const char *c)
{
	int l = 0, x = 0;
	unsigned int n = 0;

	while (c[l])
	{
		l++;
	}
	for (x = 0; x < l; x++)
	{
		if (c[l - x - 1] == '1')
			n += 1 << x;
		else if (c[l - x - 1] != '0')
			return (0);
	}
	return (n);
}
