#include <iostream>

#include <io.hpp>
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
		cout << (int) HexFormater::hex_to_byte(hf->to_hex(buffer.bytes()->at(0))) << " " << (int) buffer.bytes()->at(0) << endl;
	}
	else
	{
		cout << "Please specify filename" << endl;
	}

	return 0;
}
