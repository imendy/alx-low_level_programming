#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 1 if little endian, 0 if big endian
 */
int get_endianness(void)
{
	unsigned int a;
	char *w;

	a = 1;
	w = (char *) &a;

	return ((int)*w);
}
