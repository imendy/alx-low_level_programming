#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fp;
	ssize_t w;
	ssize_t r;

	fp = open(filename, O_RDONLY); /*open a file using fopen()*/
	if (fp == -1)/*checking if file is present, if not, return zero*/
		return (0);
	buffer = malloc(sizeof(char) * letters); /*getting the size of buffer from*/
	r = read(fp, buffer, letters); /*reading the file*/
	w = write(STDOUT_FILENO, buffer, r); /*writing to POSIX*/

	free(buffer);
	close(fp); /*closing the file, because it is  a must*/
	return (w);
}

