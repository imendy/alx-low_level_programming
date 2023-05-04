#include "main.h"

/**
 * set_bit - sets the value of a bit to 1.
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 if successful, -1 to indicate error or failure.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int a;

	if (index > 63)/*if index > 63 return -1 to show error*/
		return (-1);

	a = 1 << index;/*craete a and shift integer 1 left by the value of index*/
	*n = (*n | a);/*bitwise OR operation btw *n and a */

	return (1);/*set the bit at given index t0 1 and return 1 if suceessful*/
}
