#ifndef HAVE_OBT_HEX
#define HAVE_OBT_HEX

#include <io.hpp>
#include <string>

using namespace std;

class HexFormater {
private:
  int block_size;
  bool use_capital_letters;

public:
  HexFormater();

  // Getter / Setter
  int get_block_size();
  void set_block_size(int block_size);

  bool get_use_capital_letters();
  void set_use_capital_letters(bool capital_letters);

  // Functions
  string format_byte(byte data, char offset);
  string format(BinaryBuffer *data);
};

#endif
