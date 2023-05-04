#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0.
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 ifsuccessful, -1 to indicate error and failure.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int a;

	if (index > 63)/*if index is > 63 return -1 to indicate error*/
		return (-1);

	a = 1 << index;/*shift integer 1 left by the value of index*/

	if (*n & a)/*perform a bitwise AND operation btw *n and a, if not 0 then 1*/
		*n ^= a;/*perform bitwise XOR (^) operation btw *n and a*/

	return (1);/*return 1 if successful*/
}
