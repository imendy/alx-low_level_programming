#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int dig;
	ssize_t lett, alp;
	char *bufs;

	if (!filename)/* if NULL, return zero (0)*/
		return (0);

	dig = open(filename, O_RDONLY);/*open file, assign file to dig*/

	if (dig == -1)/*if dig == -1,meaning error, return zero(0)*/
		return (0);

	bufs = malloc(sizeof(char) * (letters));/*allocates memory for bufs*/
	if (!bufs)/*f malloc() fails, the function returns 0.*/
		return (0);

	lett = read(dig, bufs, letters);
	alp = write(STDOUT_FILENO, bufs, lett);

	close(dig);

	free(bufs);

	return (alp);
}
