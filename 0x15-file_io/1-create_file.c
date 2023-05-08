#include "main.h"

/**
 * create_file - to creates a file
 * @filename: the filename.
 * @text_content: the content writed in the file.
 *
 * Return: 1 if it successful. -1 if it's a failure.
 */
int create_file(const char *filename, char *text_content)
{
	int dig;
	int lett;
	int alp;

	if (!filename)/*if filename isn't valid,return (-1)*/
		return (-1);

	dig = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (dig == -1)/*if dig == -1, return -1*/
		return (-1);

	if (!text_content)/*if text_content is'nt valid,then empty str*/
		text_content = "";

	for (lett = 0; text_content[lett]; lett++)
		;

	alp = write(dig, text_content, lett);

	if (alp == -1)
		return (-1);

	close(dig);

	return (1);
}
