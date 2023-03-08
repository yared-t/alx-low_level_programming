#include "main.h"

/**
 * _print_rev_recursion - print in reverse order
 * @s: used to store string
 */
void _print_rev_recursion(char *s)
{
		if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
