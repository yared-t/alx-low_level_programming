#include "main.h"

/**
 * 3-islower.c - used to identifywhether lower or not
 * Return: 1 if lowercase Return: 0 ifuppercase
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z' )
		return (1);
	else 
		return (0);
}
