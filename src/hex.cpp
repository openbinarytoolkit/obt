#include <hex.hpp>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

HexFormater::HexFormater(){
  block_size = 1;
  set_use_capital_letters(true);
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
  offset = 7;
  if(!use_capital_letters)
    offset += 32;
}

string HexFormater::to_hex(byte data){
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

string HexFormater::to_hex(BinaryBuffer *data){
  string s = "";
  vector<byte> *buffer = data->bytes();
  for(unsigned int i=0; i<buffer->size(); i++){
    s += to_hex(buffer->at(i));
    if (i%1==0)
      s+= " ";
  }

  return s;
}

byte HexFormater::hex_to_byte(string hex){
  vector<char> data(hex.begin(), hex.end());
  byte tmp, b;

  if(data.size() != 2){
    cout << "String does not contain two hex characters!" << endl;
    return 0;
  }

  tmp = data.at(0) - 48;
  if(tmp >= 49)
    tmp -= 39;
  else if (tmp >= 17)
    tmp -= 7;
  b = tmp << 4;

  tmp = data.at(1) - 48;
  if(tmp >= 49)
    tmp -= 39;
  else if (tmp >= 17)
    tmp -= 7;
  b += tmp;

  return b;
}

BinaryBuffer *HexFormater::hex_to_bytes(string hex){
  char c = ' ';
  hex.erase(remove(hex.begin(), hex.end(), c), hex.end());
  if(hex.length() % 2 != 0){
    cout << "String does not contain an even number of hex characters!" << endl;
    return NULL;
  }

  vector<byte> *buffer = new vector<byte>;
  for(unsigned int i=0; 2*i<hex.length(); i++){
    buffer->push_back(hex_to_byte(hex.substr(2*i, 2)));
  }
  return new BinaryBuffer(buffer);
}
