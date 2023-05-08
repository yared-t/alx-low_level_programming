#include "main.h"

/**
 * main - progrma used to copy file
 * @ac: argument counter
 * @av: argument holder
 * Return: success
 */

int main(int ac, char **av)
{
	char c[1024];
	int f_f, f_t;
	ssize_t  l_w, c_f, l_r = 1024;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to\n");
		exit(97);
	}
	f_f = open(av[1], O_RDONLY);
	if (f_f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]),
		exit(98);
	}
	f_t = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (f_t == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(99); }
	while (l_r == 1024)
	{
		l_r = read(f_f, c, 1024);
		if (l_r == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
			exit(98); }
		l_w = write(f_t, c, l_r);
		if (l_w == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99); }
	}
	c_f = close(f_f);
	if (c_f == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", f_f);
		exit(100); }
	c_f = close(f_t);
	if (c_f == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", f_t);
		exit(100); }
	return (0);
}
