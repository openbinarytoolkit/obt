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
	BinaryBuffer() : BinaryBuffer(0) {}
	BinaryBuffer(size_t size);
	~BinaryBuffer();

	static BinaryBuffer new_from_file(string filename);

	vector<byte> *bytes(void);
	BinaryBuffer slice(size_t start, size_t len);
	string get_string_at_offset(size_t offset);
};

#endif
