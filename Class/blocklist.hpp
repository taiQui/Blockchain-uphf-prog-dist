#ifndef blocklist_hpp
#define blocklist_hpp


#include <iostream>
#include <string>

#include "block.hpp"

class BlockList {
private:
  Block* _currentBlock;
  int _length;
public:
  BlockList();
  ~BlockList();

  int getLength();
  Block getBlock();
  void setFirstBlock(Block*);
  bool checkIndex(int);
  void addBlock(Block*);
  int removeBlock(string);
  int size();
};



#endif
