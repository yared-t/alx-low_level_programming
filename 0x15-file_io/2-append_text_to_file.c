#include "main.h"

/**
 * append_text_to_file - program used to append a file
 * @filename: used to store the file name to be append
 * @text_content: used to store the text content
 * Return: success
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int s, n = 0;
	ssize_t nl;

	if (!filename)
		return (-1);
	s = open(filename, O_WRONLY | O_APPEND);
	if (s == -1)
	{
		return (-1);
	}
	if (text_content)
	{
		while (text_content[n])
			n++;
		nl = write(s, text_content, n);
		if (nl == -1)
		{
			close(n);
			return (-1);
		}
	}
	close(n);
	return (1);
}
