#include "main.h"
/**
 * binary_to_uint - used to convert binary to decimal
 * @b: stores the binarry number
 * Return: number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int len = 0;
	int i = 0;

	while (b[len])
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		if (b[len - i - 1] == '1')
			num += 1 << i;
		else if (b[len - i - 1] != '0')
			return (0);
	}
	return (num);
}
