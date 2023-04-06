#include "main.h"

/**
 * get_endianness - program used to check
 * Return: o
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *) &x;

	if (*c)
		return (1);
	else
		return (0);
}
