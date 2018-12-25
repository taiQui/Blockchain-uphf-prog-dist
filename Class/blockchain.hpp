#ifndef blockchain_hpp
#define blockchain_hpp

#include <iostream>
#include <string>
#include "block.hpp"
#include <ctime>
#include "blocklist.hpp"
class Blockchain {

private:
  BlockList* _bl;

  int _length;
public:
  int getlength();
  void setlength(int);

  Blockchain();
  ~Blockchain();

  void addBlock(Block*);
  void removeBlock(string);
  Block readBlock(int);
  bool checkIndex(int);

  void* run();

};


#endif
