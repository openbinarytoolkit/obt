#ifndef HAVE_OBT_IO
#define HAVE_OBT_IO

#include <vector>
#include <iostream>
#include <string>

using namespace std;

typedef char byte;

class BinaryBuffer
{
private:
	vector<byte> *buffer;

public:
	BinaryBuffer(size_t size);
	BinaryBuffer(vector<byte> *buffer);
	~BinaryBuffer();

	static BinaryBuffer new_from_file(string filename);

	vector<byte> *bytes(void);
};

#endif
