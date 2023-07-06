#include "hash_tables.h"

/**
 * hash_djb2 - function to compute hash of 'str' using djb2
 * @str: string to hash
 *
 * Return: value of 64 bits hash
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int my_hs;
	int h;

	my_hs = 5381;
	while ((h = *str++))
	{
		my_hs = ((my_hs << 5) + my_hs) + c;
	}
	return (my_hs);
}

