#ifndef HAVE_OBT_ELF
#define HAVE_OBT_ELF

#include <io.hpp>
#include <elf.h>

class Section{
private:
	Elf64_Shdr header;
	BinaryBuffer *data;
	string name;
public:
	Section();
	~Section();

	Elf64_Shdr get_header();
	Elf64_Shdr *get_header_address();
	BinaryBuffer *get_data_address();
	void set_data_address(BinaryBuffer *buffer);
	string get_name();
	void set_name(string new_name);
};

class ELFFile64
{
private:
	Elf64_Ehdr elf_header;
	vector<Section*> sections;

public:
	ELFFile64(BinaryBuffer *buffer);
	~ELFFile64();

	Section *get_section(int section_number);
	Elf64_Ehdr get_elf_header();
};

#endif
