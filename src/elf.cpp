#include <elf.hpp>
#include <cstring>
#include <iostream>

// Section class
// Constructor
Section::Section(){
	data = NULL;
}

// Destructor
Section::~Section(){
	if(data != NULL)
		delete data;
}

// Gets the section header
Elf64_Shdr Section::get_header(){
	return header;
}

// Gets the section header address
Elf64_Shdr *Section::get_header_address(){
	return &header;
}

// Gets the data address
BinaryBuffer *Section::get_data_address(){
	return data;
}

// Sets the data Address
void Section::set_data_address(BinaryBuffer *buffer){
	if (data != NULL)
		delete data;
	data = buffer;
}

// Gets the section name
string Section::get_name(){
	return name;
}

// sets the section name
void Section::set_name(string new_name){
	name = new_name;
}

// ELFFile64 class
// Constructor
ELFFile64::ELFFile64(BinaryBuffer *buffer)
{
	// Get elf header
	//this->buffer = buffer;
	memcpy(&elf_header, buffer->bytes()->data(), sizeof(Elf64_Ehdr));

	//Get name section header
	Elf64_Shdr name_section_header;
	// offset = (offset to section header table) + (index of the section containing the names) * (size of a section header table entry)
	size_t name_section_offset = elf_header.e_shoff + elf_header.e_shstrndx * elf_header.e_shentsize;
	memcpy(&name_section_header, buffer->bytes()->data() + name_section_offset, sizeof(Elf64_Shdr));

	for(size_t i = 0; i < elf_header.e_shnum; i++)
	{
		// Get sector number i
		Section *section = new Section();
		// Get secion header
		memcpy(section->get_header_address(), buffer->bytes()->data() + elf_header.e_shoff + i * elf_header.e_shentsize, sizeof(Elf64_Shdr));
		// Get section data
		section->set_data_address(new BinaryBuffer(section->get_header().sh_size));
		memcpy(section->get_data_address()->bytes()->data(), buffer->bytes()->data() + section->get_header().sh_offset, section->get_header().sh_size);
		// Get section name
		// name = (offset to the name section in the file image) + (offset to the name of sector number i in the name section)
		section->set_name(buffer->get_string_at_offset(name_section_header.sh_offset + section->get_header().sh_name));

		// Add section to vection
		sections.push_back(section);


		//cout << "Section " << i << " Name at: " << (name_section_header.sh_offset + section->get_header().sh_name) << endl;
		//cout << section->get_name() << endl;
	}
}

// Destructor
ELFFile64::~ELFFile64()
{
	for(unsigned int i = 0; i<sections.size(); i++){
		delete sections.at(i);
	}
}

// Gets a Section
Section *ELFFile64::get_section(int section_number){
	return sections.at(section_number);
}

// Gets the elf header
Elf64_Ehdr ELFFile64::get_elf_header(){
	return elf_header;
}
