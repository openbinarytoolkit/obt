#include <iostream>
#include <io.hpp>

#include <elf.hpp>
#include <hex.hpp>


using namespace std;

int main(int argc, char**argv)
{
	cout << "OpenBinaryToolkit" << endl;

	if(argc > 1)
	{
		BinaryBuffer buffer = BinaryBuffer::new_from_file(argv[1]);
		HexFormater *hf = new HexFormater();
		for(int x = 0; x < 4; x++)
		{
			cout << hf->to_hex(buffer.bytes()->at(x)) << " ";
		}
		cout << endl << "------ " << endl;
		cout << "Size: " << buffer.bytes()->size() << " bytes" << endl;

		ELFFile64 elf(&buffer);

		cout << elf.get_elf_header().e_shstrndx << endl;

		//BinaryBuffer buffer2 = elf.get_section(14/*elf.get_elf_header().e_shstrndx*/).data;
		//cout << hf->to_hex(&buffer2) << endl;


		delete hf;
	}
	else
	{
		cout << "Please specify filename" << endl;
	}

	return 0;
}
