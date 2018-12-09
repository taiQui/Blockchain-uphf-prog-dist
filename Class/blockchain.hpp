#ifndef blockchain_hpp
#define blockchain_hpp

#include <iostream>
#include <string>
#include "block.hpp"

class Blockchain {

private:
//liste chainée block
//Add timer
  int _length;
public:
  int getlength();
  void setlength(int);

  void addBlock(Block*);
  void removeBlock(string);
  Block readBlock(int);
  bool checkIndex(int);

};


#endif
