#include <io.hpp>
#include <fstream>
#include <cstring>

using namespace std;

BinaryBuffer::BinaryBuffer(size_t size)
{
	buffer = new vector<byte>(size);
}

BinaryBuffer::BinaryBuffer(vector<byte> *buffer){
	this->buffer = buffer;
}

BinaryBuffer::~BinaryBuffer()
{
	delete buffer;
}

BinaryBuffer BinaryBuffer::new_from_file(string filename)
{
	ifstream file(filename, ios::binary | ios::ate);
	size_t size = file.tellg();
	file.seekg(0, std::ios::beg);

	BinaryBuffer ret(size);
	if (! file.read(ret.bytes()->data(), size))
	{
		cout << "Error Reading File" << endl;
	}

	return ret;
}

vector<byte> *BinaryBuffer::bytes(void)
{
	return buffer;
}

BinaryBuffer BinaryBuffer::slice(size_t start, size_t len)
{
	BinaryBuffer ret(len);
	memcpy(ret.bytes()->data(), bytes()->data() + start, len);
	return ret;
}

string BinaryBuffer::get_string_at_offset(size_t offset)
{
	string ret("");
	for(size_t i = offset; bytes()->at(i) != 0; i++)
	{
		ret += bytes()->at(i);
	}
	return ret;
}
