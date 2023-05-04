#include "main.h"

/**
 * flip_bits - returns the number of bits you would
 * need to flip to get from one number to another
 * @n: number one.
 * @m: number two.
 *
 * Return: number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int um_bs;

	for (um_bs = 0; n || m; n >>= 1, m >>= 1)/*iterate, if diff increase um_bs*/
	{
		if ((n & 1) != (m & 1))
			um_bs++;
	}

	return (um_bs);
}
