#include "main.h"

/**
 * print_sign - used to print the sign of a number
 * Return: 1 if positive Return: 0 if 0 Return: -1 if negative
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
