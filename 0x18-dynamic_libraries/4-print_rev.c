#include "main.h"

/**
 * print_rev - pritn the reverse of astring
 * @s: used to store a string
 */
void print_rev(char *s)
{
	int len = 0;
	int x;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	s--;

	for (x = len; x > 0; x--)
	{
		_putchar(*s);
		s--;
	}
	_putchar('\n');
}
