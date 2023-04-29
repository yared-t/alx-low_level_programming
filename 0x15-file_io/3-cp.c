#include "main.h"
/**
 * error - program used to give error message
 * @msg: the message
 * @filename: used to store the filename
 * @exit_code: used to excet the code
 */
void error(char *msg, char *filename, int exit_code)
{
	dprintf(STDERR_FILENO, msg, filename);
	exit(exit_code);
}
/**
 * main - used to run the main code
 * @argc: arg counter
 * @argv: stores the args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t  l_read = 1024, l_write, close_file;
	char content[1024];

	if (argc != 3)
	{ dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97); }
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
		exit(98); }
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99); }
	while (l_read == 1024)
	{
		l_read = read(file_from, content, 1024);
		if (l_read == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98); }
		l_write = write(file_to, content, l_read);
		if (l_write == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99); }
	}
	close_file = close(file_from);
	if (close_file == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", file_from);
		exit(100); }
	close_file = close(file_to);
	if (close_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", file_to);
		exit(100);
	}
	return (0);
}
