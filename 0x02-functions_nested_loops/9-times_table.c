#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int i;
	int j;
	int firstNumber;
	int lastNumber;
	int product;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			product = j * i;
			if (product > 9)
			{
				lastNumber = product % 10;
				firstNumber = (product - last number) / 10;
				_putchar(44);
				_putchar(32);
				_putchar(firstNumber + '0');
				_putchar(lastNumber + '0');

			}
			else
			{
				if (j != 0)
				{
					_putchar(44);
					_putchar(32);
					_putchar(32);
				}
				_putchar(product + '0');
			}
		}
		_putchar('\n');
	}
}
