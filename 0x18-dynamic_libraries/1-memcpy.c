#include "main.h"

/**
 * _memcpy - used to copy
 * @dest: used to store the destination
 * @src: used to store the sourfce
 * @n: used to store int
 * Return: copeyed memory with n byte
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}

