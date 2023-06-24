#include "main.h"

/**
 * swap_int - used to swap values
 * @a: used tos tore anumber
 * @b: used to store anumber
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
