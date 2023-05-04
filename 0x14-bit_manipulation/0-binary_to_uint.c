#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Return: If b is NULL or contains chars not 0 or 1 - 0.
 *         Otherwise - the converted number.
 */
unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int num_val = 0;

	if (!b) /* if not b return zero (0)*/
		return (0);

	for (a = 0; b[a]; a++)/* iteration */
	{
		if (b[a] < '0' || b[a] > '1')
			return (0);
		num_val = 2 * num_val + (b[a] - '0');
	}
	return (num_val);
}
