#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: number to set
 * @index: index at which to set bit
 *
 * Return: 1 for success, or -1 for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long intdig;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	dig = 1 << index;
	*n = *n | dig;
	return (1);
}
