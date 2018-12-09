#include "blocklist.hpp"


BlockList::BlockList(){

}

BlockList::~BlockList(){

}

Block BlockList::getInferiorBlock(){
  return (*this->_currentBlock).getInferiorBlock();
}

Block BlockList::getBlock(){
  return *this->_currentBlock;
}

void BlockList::setBlock(Block block){
  this->_currentBlock = &block;
}

Block BlockList::getBlockWithIndexDesc(int index){

}

bool BlockList::checkIndex(int index){
  Block* aux = NULL;
  for(int i = 0; i < index ;i++){
    // aux = new Block()
  }
}
