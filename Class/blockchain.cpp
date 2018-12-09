#include "blockchain.hpp"

void Blockchain::addBlock(Block* block){

}

void Blockchain::removeBlock(string hash){

}

Block Blockchain::readBlock(int index){
  //get block in traveling to all chain list
  // to avoid error on compilation need to change when implemented
  return *(new Block());
}

bool Blockchain::checkIndex(int index){
  return(index >= 0 && index <= this->_length);
}

int Blockchain::getlength(){
  return this->_length;
}

void Blockchain::setlength(int size){
  this->_length = size;
}
