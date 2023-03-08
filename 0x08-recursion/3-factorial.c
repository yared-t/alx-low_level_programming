#include "main.h"

/**
 * factorial - used to calcualate factorial
 * @n: used to store number
 * Return: 0 (Success)
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
