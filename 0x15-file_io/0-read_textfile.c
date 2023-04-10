#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - prpgqm uweed to read
 * @filename: used to store file namwfile
 * @letters: used to store the letter
 * Return: NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t t, w, f;
	char *b;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return  (0);
	b = malloc(sizeof(char) * letters);
	t = read(f, b, letters);
	w = write(STDOUT_FILENO, b, t);
	free(b);
	close(f);
	return (w);
}

