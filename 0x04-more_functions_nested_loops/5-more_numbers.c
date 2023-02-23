#include "main.h"

/**
 * more_numbers - program used to print 0 - 14
 */
void more_numbers(void)
{
	int n, c;

	for (n = 0; n < 10; n++)
	{
		for (c = 0; c < 15; c++)
		{
			if (c >= 10)
			{
				_putchar(c / 10);
				_putchar(c % 10);
			}
		
		}
		_putchar('\n');
	}
}
