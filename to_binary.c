#include "main.h"

/**
 * decimalToBinary- converts int to binary
 * @num: integer to convert
 *
 * Returns void
 */


void decimalToBinary(int num)
{
	int binary[32]; 
	int index = 0;
	int i;

	if (num == 0)
	{
		_printf("0"); 
		return;
	}
 

    

    /* Convert decimal to binary */
	while (num > 0)
	{
		binary[index] = num % 2;
		num = num / 2;
		index++;
	}

	for (i = index - 1; i >= 0; i--)
	{
		_printf("%d", binary[i]);
	}
}