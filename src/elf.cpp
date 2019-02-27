#include <elf.hpp>
#include <cstring>
#include <iostream>

ELFFile64::ELFFile64(BinaryBuffer buffer)
{
	this->buffer = buffer;
	memcpy(&elf_header, buffer.bytes()->data(), sizeof(Elf64_Ehdr));

	size_t name_section_offset = elf_header.e_shoff + elf_header.e_shstrndx * elf_header.e_shentsize;
	BinaryBuffer name_section_header_buffer = this->buffer.slice(name_section_offset, sizeof(Elf64_Shdr));
	Elf64_Shdr name_section_header;
	memcpy(&name_section_header, name_section_header_buffer.bytes()->data(), sizeof(Elf64_Shdr));

	for(size_t i = 0; i < elf_header.e_shnum; i++)
	{
		BinaryBuffer section_header_buffer = this->buffer.slice(elf_header.e_shoff + i * elf_header.e_shentsize, sizeof(Elf64_Shdr));
		Elf64_Shdr section_header;
		memcpy(&section_header, section_header_buffer.bytes()->data(), sizeof(Elf64_Shdr));


		cout << "Section Name at: " << (name_section_header.sh_offset + section_header.sh_name) << endl;
		cout << buffer.get_string_at_offset(name_section_header.sh_offset + section_header.sh_name) << endl;
	}
}

ELFFile64::~ELFFile64()
{

}
