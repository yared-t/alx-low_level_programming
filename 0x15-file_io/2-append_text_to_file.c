#include "main.h"

/**
 * append_text_to_file - program used to append text to file
 * @filename: used to store the file name
 * @text_content: used to store the content of the file
 * Return: 1 or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int f, l = 0, w;

	if (!filename)
		return (-1);
	f = open(filename, O_WRONLY | O_APPEND);
	while (text_content[l])
		l++;
	if (text_content)
		w = write(f, text_content, l);
	if (w == -1)
	{
		close(f);
		return (-1);
	}
	else
		return (1);
	close(f);
	return (1);
}
