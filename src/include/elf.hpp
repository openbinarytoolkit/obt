#ifndef HAVE_OBT_ELF
#define HAVE_OBT_ELF

#include <io.hpp>
#include <elf.h>

class ELFFile64
{
private:
	BinaryBuffer buffer;
	Elf64_Ehdr elf_header;


public:
	ELFFile64(BinaryBuffer buffer);
	~ELFFile64();
};

#endif
