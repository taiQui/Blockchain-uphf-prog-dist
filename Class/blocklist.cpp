#include "blocklist.hpp"


BlockList::BlockList(){

}

BlockList::~BlockList(){

}

// Block BlockList::getInferiorBlock(){
//   return (*this->_currentBlock).getInferiorBlock();
// }

Block BlockList::getBlock(){
  return *this->_currentBlock;
}

void BlockList::setFirstBlock(Block* block){
  this->_currentBlock = block;
}

Block* BlockList::getBlockWithIndexDesc(int index){
  if(checkIndex(index))
    return NULL;
  Block aux;
  for( int i = 0 ; i < index ; i++){
     aux = new Block(this->_currentBlock->getInferiorBlock()->getHash(),this->_currentBlock->getInferiorBlock()->getInferiorBlock(),this->_currentBlock->getInferiorBlock()->getLength(),this->_currentBlock->getInferiorBlock()->getAllList());
    aux = *(aux.getInferiorBlock());
  }
  return(aux);
}

bool BlockList::checkIndex(int index){
  bool continuer = true;
  Block aux = *this->_currentBlock;
  int i = 0;
  while(continuer && i < index){
      if(aux.getInferiorBlock() != NULL ){
        aux = *(aux.getInferiorBlock());
        i++;
      } else {
        continuer = false;
      }
  }
  return continuer;
}

void BlockList::addBlock(Block* nextblock){
  nextblock->setInferiorBlock(this->_currentBlock);
  this->_currentBlock = nextblock;
}

int BlockList::removeBlock(string hash){
  Block aux = *this->_currentBlock;
  bool continuer = true;
  int i = 0;
  while(continuer){
    if(aux.getHash() == hash){
      continuer = false;
    } else {
      if(aux.getInferiorBlock() != NULL ){
        aux = *(aux.getInferiorBlock());
        i++;
      } else {
        continuer = false;
      }
    }
  }
  if(aux.getHash() == hash){
    for(int j = 0 ; j < i ; j++){
      Block* supp = new Block(this->_currentBlock->getInferiorBlock()->getHash(),this->_currentBlock->getInferiorBlock()->getInferiorBlock(),this->_currentBlock->getInferiorBlock()->getLength(),this->_currentBlock->getInferiorBlock()->getAllList());
      delete this->_currentBlock;
      this->_currentBlock = supp;
    }
    return(i);
  } else {
    return(-1);
  }
}
