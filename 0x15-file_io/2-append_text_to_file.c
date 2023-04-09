#include "main.h"

/**
 * append_text_to_file - a funcion that appends text at the end
 *                      of a file
 *
 * @filename: file to add data to
 * @text_content: text content to add to file
 *
 * Return: 1 if successful, -1 on failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int fp, w, wd = 0;

	if (filename == NULL)/*checking if file is present, if not, return (-1)*/
		return (-1);

	if (text_content != NULL)/*writing content to file if its not NULL*/
	{
		for (wd = 0; text_content[wd];)
			wd++;
	}

	fp = open(filename, O_WRONLY | O_APPEND);/*open,append and write permission*/
	w = write(fp, text_content, wd); /*writing to the file*/

	if (fp == -1 || w == -1)/*checking if file || write is present*/
		return (-1);

	close(fp);/* Always remember to close the file bro!*/

	return (1);
}

