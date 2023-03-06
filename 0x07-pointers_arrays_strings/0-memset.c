#include "main.h"

/**
 * *_memset - program that fills with constant memory
 * @s: used to store character
 * @b: used to store character
 * @n: used to store a number
 * Return: changed array
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
