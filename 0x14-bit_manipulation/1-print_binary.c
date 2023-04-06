#include "main.h"

/**
 * print_binary - program used to print binary
 * @n: used to store the number
 */
void print_binary(unsigned long int n)
{
	int a;


	for (a = 31; a >= 0; a--)
	{
		if ((n >> a & 1))
			printf("1");
		else
			printf("0");
	}
}
