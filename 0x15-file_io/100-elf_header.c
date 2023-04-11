#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * error - used to print error
 * @m: used to store the message
 */
void error(char *m)
{
	fprintf(stderr, "%s\n", m);
	exit(98);
}
/**
 * elf_header - header function
 * @header: used to store the header
 */
void elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("ELF header:\n");
	printf("  magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	printf("class:%s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("Data:%s\n", header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "2's coplement, little endian");
	printf("   version:                   %d\n", header->e_ident[EI_VERSION]);
	printf("   OS/ABI:                    %d\n", header->e_ident[EI_OSABI]);
	printf("   ABI version:               %d\n", header->e_ident[EI_ABIVERSION]);
	printf("   type:                      %d\n", header->e_type);
	printf("   Entry point address:       0x%lx\n", header->e_entry);
}

/**
 * main - program used to run
 * @argc: argv counter
 * @argv: array used to contain args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int f;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		error("elf_header elf_filename");
	}

	f = open(argv[1], O_RDONLY);
	if (f == -1)
		error("can't open file");
/*	char buf[1024];*/

	if (read(f, &header, sizeof(header)) != sizeof(header))
		error("unable to read ELF header");
	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 || header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
		error("not an elf file");
	elf_header(&header);
	if (close(f) == -1)
	{
		error("unable to close file");
	}
	return (0);
}

