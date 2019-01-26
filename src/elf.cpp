#include <elf.hpp>
#include <cstring>
#include <iostream>

ELFFile64::ELFFile64(BinaryBuffer buffer)
{
	this->buffer = buffer;
	memcpy(&elf_header, buffer.bytes()->data(), sizeof(Elf64_Ehdr));
	for(size_t i = 0; i < elf_header.e_shnum; i++)
	{
		BinaryBuffer section = this->buffer.slice(elf_header.e_shoff + i * elf_header.e_shentsize, elf_header.e_shentsize);

		Elf64_Shdr sec;
		memcpy(&sec, section.bytes()->data(), sizeof(Elf64_Shdr));
		size_t secNameOffset = sec.sh_name + (elf_header.e_shstrndx * elf_header.e_shentsize) + elf_header.e_shoff;
		cout << "Section Name at: " << secNameOffset  << endl;
		cout << buffer.get_string_at_offset(secNameOffset) << endl;
	}
}

ELFFile64::~ELFFile64()
{

}
