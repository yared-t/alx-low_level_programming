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
	int nr = 0, fr, ff;
	char buf[1024];

	if (argc != 3)
	{
		error("using file from  file to %s\n", argv[0], 97);
	}
	ff = open(argv[1], O_RDONLY);
	if (ff == -1)
		error("unable to read file%s\n", argv[1], 98);
	fr = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fr == -1)
	{
		error("unable to write%s\n", argv[2], 99);
	}
	while (nr >= 1024)
	{
		if (write(fr, buf, nr) != nr)
			error("unable to write to %s\n", argv[2], 98);
	}
	if (nr == -1)
		error("unable to read from %s\n", argv[1], 99);
	if (close(ff) == -1)
		error("unable to close ff %d\n", "ff", 100);
	if (close(fr) == -1)
		error("unable to close ft %d\n", "fr", 100);
	return (0);
}
