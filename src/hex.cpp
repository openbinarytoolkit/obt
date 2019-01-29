#include <hex.hpp>
#include <io.hpp>
#include <iostream>

HexFormater::HexFormater(){
  block_size = 1;
  use_capital_letters = true;
}

int HexFormater::get_block_size(){
  return block_size;
}

void HexFormater::set_block_size(int block_size){
  this->block_size = block_size;
}

bool HexFormater::get_use_capital_letters(){
  return use_capital_letters;
}

void HexFormater::set_use_capital_letters(bool use_capital_letters){
  this->use_capital_letters = use_capital_letters;
}

string HexFormater::format_byte(byte data, char offset){
  string s = "";
  unsigned char tmp = (unsigned char) (data >> 4) % 16;

  if (tmp > 9)
    tmp += offset;
  tmp += 48;
  s += tmp;

  tmp = (unsigned char)data % 16;

  if (tmp > 9)
    tmp += offset;
  tmp += 48;
  s += tmp;

  return s;
}

string HexFormater::format(BinaryBuffer *data){
  string s = "";
  char offset = 7;
  if(!use_capital_letters)
    offset += 32;
  vector<byte> *buffer = data->bytes();
  for(unsigned int i=0; i<buffer->size(); i++){
    s += format_byte(buffer->at(i), offset);
    if (i%1==0)
      s+= " ";
  }

  return s;
}
