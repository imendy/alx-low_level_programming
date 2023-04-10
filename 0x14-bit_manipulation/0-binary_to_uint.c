#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointer to a string containing a binary number
 *
 * Return: unsigned int with decimal value of binsry number, or 0 if error
 */
unsigned int binary_to_uint(const char *b)
{
	int num;
	unsigned int dig;

	dig = 0; /*initialize dig to 0*/
	if (!b) /*if b is NULL, return 0*/
		return (0);
	for (num = 0; b[num] != '\0'; num++) /*iterate through b*/
	{
		if (b[num] != '0' && b[num] != '1')
			return (0);
	}
	for (num = 0; b[num] != '\0'; num++)
	{
		dig <<= 1;
		if (b[num] == '1')
			dig += 1;
	}
	return (dig);
}
