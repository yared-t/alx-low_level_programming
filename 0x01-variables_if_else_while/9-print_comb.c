#include <stdio.h>
/**
 * main - A program prints a number with commas
 * Return: 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 48; n < 58 ; n++)
	{
		putchar(n);

			if (n != 57)
			{
				putchar(',');
				putchar(' ');
			}
	}
		putchar('\n');
		return (0);
}
