#include "main.h"

/**
 * create_file - a function that creates a file
 *
 * @filename: name of the file to create
 * @text_content: string to write to the file
 *
 * Return: 1 if successful OR -1 on faliure
*/
int create_file(const char *filename, char *text_content)
{
	int fp, w, wd = 0;

	if (filename == NULL) /*checking if filename is present, if not return(-1)*/
		return (-1);

	if (text_content != NULL) /*write content to file if its not NULL*/
	{
		for (wd = 0; text_content[wd];)
			wd++;
	}

	fp = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);/*open file*/
	w = write(fp, text_content, wd); /*writing to file*/

	if (fp == -1 || w == -1) /*check if file creation || write was successful*/
		return (-1);

	close(fp); /*Always remember to close file*/

	return (1);
}


