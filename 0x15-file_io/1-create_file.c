#include "main.h"

/**
 * create_file - used to create filew
 * @filename: used to store the file name
 * @text_content: used to store the text content
 * Return: -1 and 1
 */
int create_file(const char *filename, char *text_content)
{
	int f, w, l = 0;

	if (!filename)
		return (-1);
	f = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (f == -1)
		return (-1);
	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}
	if (text_content)
	{
		w = write(f, text_content, l);
		if (w == -1)
		{
			close(f);
			return (-1);
		}
	}
	close(f);
	return (1);
}
