#include "main.h"

/**
 * read_textfile - program used to read a file
 * @filename: used to store the file name to be read
 * @letters: used to store the number characters to be read
 * Return: success
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *w;
	int s;
	ssize_t nl;

	if (!filename)
		return (0);
	w = malloc(sizeof(char) * letters + 1);
	if (w == NULL)
		return (0);
	s = open(filename, O_RDONLY);
	if (s == -1)
	{
		free(w);
		return (0);
	}
	nl = read(s, w, sizeof(char) * letters);
	if (nl == -1)
	{
		free(w);
		close(s);
		return (0);
	}
	nl = write(STDOUT_FILENO, w, nl);
	if (nl == -1)
	{
		free(w);
		close(s);
		return (0);
	}
	free(w);
	close(s);
	return (nl);
}
