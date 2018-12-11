#ifndef blocklist_hpp
#define blocklist_hpp


#include <iostream>
#include <string>

#include "block.hpp"

class BlockList {
private:
  Block* _currentBlock;
public:
  BlockList();
  ~BlockList();

  Block getBlock();
  Block* getBlockWithIndexDesc(int);
  void setFirstBlock(Block*);
  bool checkIndex(int);
  void addBlock(Block*);
  int removeBlock(string);
};



#endif
