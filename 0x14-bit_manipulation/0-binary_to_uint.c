#include "main.h"
/**
 * binary_to_uint - program used to display int
 * @b: used to store the binary
 * Return: intiger for success
 */
unsigned int binary_to_uint(const char *b)
{
	int l = 0, x = 0;
	unsigned int n = 0;

	while (b[l])
	{
		l++;
	}
	for (x = 0; x < l; x++)
	{
		if (b[l - x - 1] == '1')
			n += 1 << x;
		else if (b[l - x - 1] != '0')
			return (0);
	}
	return (n);
}

