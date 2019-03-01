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

		ELFFile64 elf(buffer);
		BinaryBuffer *buffer2 = HexFormater::hex_to_bytes("FF 00 0F 80");

		for(int x = 0; x < 4; x++)
		{
			cout << (int)buffer2->bytes()->at(x) << " ";
		}
		cout << endl;

		delete hf;
		delete buffer2;
	}
	else
	{
		cout << "Please specify filename" << endl;
	}

	return 0;
}
