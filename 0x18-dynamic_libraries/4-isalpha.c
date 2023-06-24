#include "main.h"

/**
 * _isalpha - prints whether alpha or not
 * @c: used to store acharacter
 * Return: 1 or Return: 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
