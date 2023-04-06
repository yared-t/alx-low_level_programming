#include "main.h"

/**
 * print_binary - program used to print binary
 * @n: used to store the number
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);
	_putchar((n & 1) + '0');
}
