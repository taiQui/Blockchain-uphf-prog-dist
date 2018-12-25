#include "blockchain.hpp"

Blockchain::Blockchain(){
  this->_bl = new BlockList();
}

Blockchain::~Blockchain(){
  delete this->_bl;
}

void Blockchain::addBlock(Block* block){
  this->_bl->addBlock(block);
}

void Blockchain::removeBlock(string hash){
  this->_bl->removeBlock(hash);
}

Block Blockchain::readBlock(int index){
  Block aux = this->_bl->getBlock();
  for( int i = this->_length; i > this->_length-index ;i--){
    aux = *(aux.getInferiorBlock());
  }
  return aux;
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

void* Blockchain::run(){
  long int decompte = 0;
  while(1){
    //listen
  }
}
