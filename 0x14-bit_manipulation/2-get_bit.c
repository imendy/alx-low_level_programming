#include "main.h"

/**
 * get_bit - returns the value of a bit at a given
 * index.
 * @n: unsigned long int input.
 * @index: index of the bit.
 *
 * Return: value of the bit.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int a;

	if (n == 0 && index < 64)/*if n is == 0 and index is < 64 return 0*/
		return (0);

	for (a = 0; a <= 63; n >>= 1, a++)/*for loop iteration*/
	{
		if (index == a)/*if a is == index return the bit at the index*/
		{
			return (n & 1);
		}
	}

	return (-1);/*if no given index return -1 as error*/
}
