#include "main.h"

/**
 * print_numbers - program used to print 0-9
 * @n: used to store a number
 */
void print_numbers(void)
{
	int n;

	for (n = 48; n < 58; n++)
		_putchar(n);
	_putchar('\n');
}
