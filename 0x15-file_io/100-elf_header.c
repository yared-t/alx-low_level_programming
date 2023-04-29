#include <elf.h>
#include "main.h"
#define REV(n) ((n << 24) | (((n >> 16) << 24) >> 16) | \
(((n << 16) >> 24) << 16) | (n >> 24))
/**
 * fun - program used to give the class of ELF
 * @i: stores the ELF struct
 */
void fun(unsigned char *i)
{
	printf("  Class:                             ");
	if (i[EI_CLASS] == ELFCLASSNONE)
		printf("This class is invalid\n");
	else if (i[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (i[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", i[EI_CLASS]);
}
/**
 * os - program used to give the os
 * @i: used to store the ELF struct
 */
void os(unsigned char *i)
{
	printf("  OS/ABI:                            ");
	if (i[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (i[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (i[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (i[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (i[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (i[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (i[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (i[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (i[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (i[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", i[EI_OSABI]);
}

/**
 * type - progrma used to give the type
 * @i: used to store the ELF struct
 * @t: data to compare and print.
 */
void type(unsigned int t, unsigned char *i)
{
	i[EI_DATA] == ELFDATA2MSB ? t = t >> 8 : t;

	printf("  Type:                              ");
	if (t == ET_NONE)
		printf("NONE (Unknown type)\n");
	else if (t == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (t == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (t == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (t == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", t);
}

/**
 * entry - print the entry point
 * @i: the ELF struct
 * @e: the data to print
 * return: no return is a void func.
 */
void entry(unsigned int e, unsigned char *i)
{
	if (i[EI_DATA] == ELFDATA2MSB)
		e = REV(e);

	printf("  Entry point address:               ");
	printf("%#x\n", (unsigned int)e);
}

/**
 * main - main function used to run all the above fun
 * @argc: arg counter
 * @argv: store the pointer
 * section header: the header of this function is holberton.h
 * Return: 0 in success
 */
int main(int argc, char *argv[])
{
	int fd, _read, _close;
	Elf64_Ehdr *file;


	if (argc > 2 || argc < 2)
		dprintf(STDERR_FILENO, "Usage: error in # of args\n"), exit(98);
	file = malloc(sizeof(Elf64_Ehdr));
	if (file == NULL)
		dprintf(STDERR_FILENO, "error in allocate memory\n"), exit(98);
	fd = open(*(argv + 1), O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	_read = read(fd, file, sizeof(Elf64_Ehdr));
	if (_read == -1)
	{
		free(file);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	check(file->e_ident);
	m(file->e_ident);
	fun(file->e_ident);
	d(file->e_ident);
	update(file->e_ident);
	os(file->e_ident);
	printf("  ABI Version:                       ");
	printf("%i\n", file->e_ident[EI_ABIVERSION]);
	type(file->e_type, file->e_ident);
	entry(file->e_entry, file->e_ident);
	free(file);
	_close = close(fd);
	if (_close)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(98);
	}
	return (0);
}
