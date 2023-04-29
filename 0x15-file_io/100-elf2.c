#include "main.h"
/**
 * m - program gives magic number
 * @i: store the ELF struct
 */
void m(unsigned char *i)
{
	int j;
	int l;

	l = EI_NIDENT - 1;
	printf("  Magic:   ");
	for (j = 0; j < l; j++)
		printf("%02x ", *(i + j));
	printf("%02x\n", *(i + j));
}

/**
 * check - used to check the file
 * @i: used to store the elf
 */
void check(unsigned char *i)
{
	if (*(i) == 0x7f && *(i + 1) == 'E' && *(i + 2) == 'L' && *(i + 3) == 'F')
	{
		printf("ELF Header:\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: not valid ELF\n");
		exit(98);
	}
}
/**
 * d - program used to give the data
 * @i: stores the ELF struct
 */
void d(unsigned char *i)
{
	printf("  Data:                              ");
	if (i[EI_DATA] == ELFDATANONE)
		printf("Unknown data format\n");
	else if (i[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (i[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", i[EI_DATA]);
}
/**
 * update - program used to store the version
 * @i: stores the ELF struct
 */
void update(unsigned char *i)
{
	printf("  Version:                           ");
	if (i[EI_VERSION] == EV_CURRENT)
		printf("%i (current)\n", EV_CURRENT);
	else
		printf("%i\n", i[EI_VERSION]);
}
