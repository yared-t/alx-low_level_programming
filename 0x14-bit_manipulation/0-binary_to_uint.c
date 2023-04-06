#include "main.h"
/**
 * binary_to_uint - used to convert binary to decimal
 * @b: stores the binarry number
 * Return: number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int r = 0;
	unsigned int n = 0;
	unsigned int x;
	int y = 1;


	while (b[r + 1])
	{
		if (b[r] != '1' && b[r] != '0')
			return (0);
		r++;
	}
	for (x = 0; x < r; x++)
	{
		n += ((b[x] - '0') * y);
		y *= 2;
	}
	return (n);
}
