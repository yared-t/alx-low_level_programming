#include "main.h"

/**
 * _islower - used to identify whether lower or not
 * @c: is a variable used to store char
 * Return: 1 if lowercase Return: 0 ifuppercase
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
