#include "main.h"

/**
 * print_binary - program used to print binary
 * @i: used to store an integer
 * Return: the number
 */

void print_binary(unsigned long int i)
{
	if (i > 1)
		print_binary(i >> 1);

	_putchar((i & 1) + '0');
}
