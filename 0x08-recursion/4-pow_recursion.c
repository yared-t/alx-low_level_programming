#include "main.h"

/**
 * _pow_recursion - power recursion
 * @x: used to store number
 * @y: used to store number
 * Return: 0 (Success)
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
