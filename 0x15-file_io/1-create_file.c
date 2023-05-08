#include "main.h"

/**
 * create_file - program used to create file
 * @filename: used to store the filename need to open
 * @text_content: used to store the contetnt of the file
 * Return: success
 */

int create_file(const char *filename, char *text_content)
{
	int s, l = 0;
	ssize_t nl;

	if (!filename)
		return (1);
	s = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (s == -1)
	{
		return (-1);
	}
	if (text_content)
	{
		while (text_content[l])
			l++;
		nl = write(s, text_content, l);
		if (nl == -1)
		{
			close(s);
			return (-1);
		}
	}
	close(s);
	return (1);
}
