#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main -A used to identify the number is positive or negative
 * Return: 0 (Success)
 */ 
int main(void)
{
	int n;
	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
	{
		printf("%d is positive", n);
	}
	if (n < 0)
	{
		printf("%d is negative", n);
	}
	return (0);
}
