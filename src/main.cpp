#include <iostream>

#include <io.hpp>

using namespace std;

int main(int argc, char**argv)
{
	cout << "OpenBinaryToolkit" << endl;

	if(argc > 1)
	{
		BinaryBuffer buffer = BinaryBuffer::new_from_file(argv[1]);
		cout << " - ELF HEADER DEMO" << endl;
		for(int x = 1; x < 4; x++)
		{
			cout << (char) buffer.bytes()->at(x);
		}
		cout << endl << "------ " << endl;
		cout << "Size: " << buffer.bytes()->size() << " bytes" << endl;
	}
	else
	{
		cout << "Please specify filename" << endl;
	}

	return 0;
}
