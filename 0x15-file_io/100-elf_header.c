#include <elf.h>
#include "main.h"
#include <stdio.h>
#define REV(n) ((n << 24) | (((n >> 16) << 24) >> 16) | \
(((n << 16) >> 24) << 16) | (n >> 24))

/**
 * m - program used to dispkay magic
 * @e_in: used to store the indent
 */

void m(unsigned char *e_in)
{
	int n, l;

	l = EI_NIDENT - 1;
	printf("  Magic:   ");
	for (n = 0; n < l; n++)
		printf("%02x ", *(e_in + n));
	printf("%02x\n", *(e_in + n));
}
/**
 * ve - program used to display the version
 * @e_in: used to store the indent
 */
void ve(unsigned char *e_in)
{
	printf("  Version:                           ");
	if (e_in[EI_VERSION] == EV_CURRENT)
		printf("%i (current)\n", EV_CURRENT);
	else
		printf("%i\n", e_in[EI_VERSION]);
}
/**
 * ty - progrma used to type
 * @e_t: used to store the indent type
 * @e_in: used to store the indent
 */
void ty(unsigned int e_t, unsigned char *e_in)
{
	e_in[EI_DATA] == ELFDATA2MSB ? e_t = e_t >> 8 : e_t;

	printf("  Type:                              ");
	if (e_t == ET_NONE)
		printf("NONE (Unknown type)\n");
	else if (e_t == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (e_t == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (e_t == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (e_t == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", e_t);
}
/**
 * ver - progrma used to verify
 * @e_in: used to store the indent
 */
void ver(unsigned char *e_in)
{
	if (*(e_in) == 0x7f && *(e_in + 1) == 'E' &&
	    *(e_in + 2) == 'L' && *(e_in + 3) == 'F')
	{
		printf("ELF Header:\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: this file not is a valid ELF\n");
		exit(98);
	}
}
/**
 * cl - used to telll the class
 * @e_in: used to store the indent
 */
void cl(unsigned char *e_in)
{
	printf("  Class:                             ");
	if (e_in[EI_CLASS] == ELFCLASSNONE)
		printf("This class is invalid\n");
	else if (e_in[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_in[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_in[EI_CLASS]);
}
/**
 * ent - used to print the nerty
 * @e_en:used t store the entry
 * @e_in: used to store the indent
 */
void ent(unsigned int e_en, unsigned char *e_in)
{
	if (e_in[EI_DATA] == ELFDATA2MSB)
		e_en = REV(e_en);

	printf("  Entry point address:               ");
	printf("%#x\n", (unsigned int)e_en);
}
/**
 * da - progrma used to display the data
 * @e_in: used to data
 */
void da(unsigned char *e_in)
{
	printf("  Data:                              ");
	if (e_in[EI_DATA] == ELFDATANONE)
		printf("Unknown data format\n");
	else if (e_in[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_in[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", e_in[EI_DATA]);
}
/**
 * osa - program used to display the osabi
 * @e_in: used to store the indent
 */
void osa(unsigned char *e_in)
{
	printf("  OS/ABI:                            ");
	if (e_in[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (e_in[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (e_in[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (e_in[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (e_in[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (e_in[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (e_in[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (e_in[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (e_in[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (e_in[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", e_in[EI_OSABI]);
}
/**
 * main - progrma used to run all
 * @ac: used count
 * @av: used to store the argument
 * Return: success
 */
int main(int ac, char *av[])
{
	int fd, _r, _c;
	Elf64_Ehdr *f;

	if (ac > 2 || ac < 2)
		dprintf(STDERR_FILENO, "Usage: error in # of args\n"), exit(98);
	f = malloc(sizeof(Elf64_Ehdr));
	if (f == NULL)
		dprintf(STDERR_FILENO, "error in allocate memory\n"), exit(98);
	fd = open(*(av + 1), O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(av + 1));
		exit(98);
	}
	_r = read(fd, f, sizeof(Elf64_Ehdr));
	if (_r == -1)
	{
		free(f);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(av + 1));
		exit(98);
	}
	ver(f->e_ident);
	m(f->e_ident);
	cl(f->e_ident);
	da(f->e_ident);
	ve(f->e_ident);
	osa(f->e_ident);
	printf("  ABI Version:                       ");
	printf("%i\n", f->e_ident[EI_ABIVERSION]);
	ty(f->e_type, f->e_ident);
	ent(f->e_entry, f->e_ident);
	free(f);
	_c = close(fd);
	if (_c)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(98);
	}
	return (0);
}
