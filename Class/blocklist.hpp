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

  Block getInferiorBlock();
  Block getBlock();
  Block getBlockWithIndexDesc(int);
  void setBlock(Block);
  bool checkIndex(int);
};



#endif
