#include "main.h"

/**
 * _strlen - used to calculate the length of string
 * @s: used to store char
 * Return: len
 */
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count = count + 1;
		s++;
	}
	return (count);
}
