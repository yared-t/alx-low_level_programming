#include "main.h"
/**
 * get_endianness - program used to get the indians
 * Return: value
 */
int get_endianness(void)
{
	char *t;
	unsigned int n = 1;

	t = (char *) &n;

	return (*t);
}

