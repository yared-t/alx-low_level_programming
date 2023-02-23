#include "main.h"

/**
 * print_line - used to print a lines
 * @n: used to store data
 */
void print_line(int n)
{
	int c;

	for (c = 0; c < n; c++)
		_putchar('_');
	_putchar('\n');
}
