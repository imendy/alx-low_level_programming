#include "main.h"

/**
 * append_text_to_file - appending text at the end of a file
 * @filename: pointer filename.
 * @text_content: the added pointer content.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int dig;
	int lett;
	int alp;

	if (!filename)
		return (-1);

	dig = open(filename, O_WRONLY | O_APPEND);

	if (dig == -1)
		return (-1);

	if (text_content)
	{
		for (lett = 0; text_content[lett]; lett++)
			;

		alp = write(dig, text_content, lett);

		if (alp == -1)
			return (-1);
	}

	close(dig);

	return (1);
}
