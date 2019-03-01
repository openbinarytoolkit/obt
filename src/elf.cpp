#include <elf.hpp>
#include <cstring>
#include <iostream>

ELFFile64::ELFFile64(BinaryBuffer buffer)
{
	this->buffer = buffer;
	// Get elf header
	memcpy(&elf_header, buffer.bytes()->data(), sizeof(Elf64_Ehdr));

	//Get name section header
	Elf64_Shdr name_section_header;
	// offset = (offset to section header table) + (index of the section containing the names) * (size of a section header table entry)
	size_t name_section_offset = elf_header.e_shoff + elf_header.e_shstrndx * elf_header.e_shentsize;
	memcpy(&name_section_header, buffer.bytes()->data() + name_section_offset, sizeof(Elf64_Shdr));

	for(size_t i = 0; i < elf_header.e_shnum; i++)
	{
		// Get sector number i
		Elf64_Shdr section_header;
		memcpy(&section_header, buffer.bytes()->data() + elf_header.e_shoff + i * elf_header.e_shentsize, sizeof(Elf64_Shdr));

		// name = (offset to the name section in the file image) + (offset to the name of sector number i in the name section)
		cout << "Section Name at: " << (name_section_header.sh_offset + section_header.sh_name) << endl;
		cout << buffer.get_string_at_offset(name_section_header.sh_offset + section_header.sh_name) << endl;
	}
}

ELFFile64::~ELFFile64()
{

}
