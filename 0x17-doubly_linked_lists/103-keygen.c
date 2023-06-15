#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - generate a key depending on a username for crackme5
 * @argc: number of arguments passed
 * @argv: arguments passed to main
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int j, k;
	size_t name_len, the_add;
	char *r = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char ep[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	name_len = strlen(argv[1]);
	ep[0] = r[(name_len ^ 59) & 63];
	for (j = 0, the_add = 0; j < name_len; j++)
		the_add += argv[1][j];
	ep[1] = r[(the_add ^ 79) & 63];
	for (j = 0, k = 1; j < name_len; j++)
		k *= argv[1][j];
	ep[2] = r[(k ^ 85) & 63];
	for (k = argv[1][0], j = 0; j < name_len; j++)
		if ((char)k <= argv[1][j])
			k = argv[1][j];
	srand(k ^ 14);
	ep[3] = r[rand() & 63];
	for (k = 0, j = 0; j < name_len; j++)
		k += argv[1][j] * argv[1][j];
	ep[4] = r[(k ^ 239) & 63];
	for (k = 0, j = 0; (char)j < argv[1][0]; j++)
		k = rand();
	ep[5] = r[(k ^ 229) & 63];
	printf("%s\n", ep);
	return (0);
}
