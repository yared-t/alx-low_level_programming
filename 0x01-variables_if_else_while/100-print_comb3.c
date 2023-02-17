#include <stdio.h>
/**
 * main - A program prints smallest combiantion of digits
 * Return: 0 (Success)
 */
int main(void)
{
	int n;
	int y;

	for (n = 48 ; n <= 58 ; n++)
	{
		for (y = 49 ; y <= 57 ; y++)
		{
			if (n < y)
			{
				putchar(n);
				putchar(y);
				if (n != 56 || y != 57)
				{
					putchar(',');
					putchar(' ');
				}	
	
			}
		}
	}
	putchar('\n');
	return (0);
}
