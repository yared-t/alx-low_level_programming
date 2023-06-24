#include "main.h"

/**
 * reverse_array - used to reverse an array
 * @a: store a pointer
 * @n: number
 */
void reverse_array(int *a, int n)
{
	int i;
	int t;

	for (i = 0; i < n--; i++)
	{
		t = a[i];
		a[i] = a[n];
		a[n] = t;
	}
}
