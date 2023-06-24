#include "main.h"

/**
 * _puts - used to put acharacter
 * @str: used to store string
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}
