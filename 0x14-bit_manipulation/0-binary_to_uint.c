#include "main.h"
/**
 * binary_to_uint - used to convert binary to decimal
 * @b: stores the binarry number
 * Return: number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i = 0, ba = 1;

	if (b = NULL)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}
	while (i >= 0)
	{
		num += ((b[i] - '0') * ba);
		ba *= 2;
		i--;
	}
	return (num);
}
