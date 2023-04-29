#include "main.h"

/**
 * append_text_to_file - program used to append text to file
 * @filename: used to store the file name
 * @text_content: used to store the content of the file
 * Return: 1 or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int f, l = 0;
	ssize_t n;

	if (!filename)
		return (-1);
	f = open(filename, O_WRONLY | O_APPEND);
	if (f == -1)
		return (-1);
	if (text_content)
	{
		while (text_content[l])
                l++;
		n = write(f, text_content, l);
		if (n == -1)

		{
			close(f);)
			return ( -1);
		}
	}
	close(f);
	return (1);
}
