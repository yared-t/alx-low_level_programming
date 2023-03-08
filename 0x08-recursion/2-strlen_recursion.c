#include "main.h"

/**
 * _strlen_recursion - used to count the string length
 * @s: used to store a string
 * Return: 0 (Success)
 */
int _strlen_recursion(char *s)
{
	int n;

	n = 0;
	if (*s)
	{
		n++;
		n += _strlen_recursion(s + 1);
	}
	return (n);
}
