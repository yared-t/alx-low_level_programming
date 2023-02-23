#include "main.h"

/**
 * print_square - program used to print squares
 * @size: used store the size
 */
void print_square(int size)
{
	if (size <= 0)
		_putchar('\n');
	else
	{
	int y;
	int z;

	for (y = 0; y < size; y++)
	{
		for (z = 0; z < size; z++)
			_putchar('#');
		_putchar('\n');
	}
	}
}
