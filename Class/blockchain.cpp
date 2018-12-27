#include "blockchain.hpp"

Blockchain::Blockchain(){ 

}

Blockchain::Blockchain(vector<int> socket, vector<pthread_t> id, int length){
  this->_bl = new BlockList();
  this->_socket = socket;
  this->_id = id;
  this->_length = length;
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

int Blockchain::getSocketByIndex(int index){
  return this->_socket.at(index);
}

vector<int> Blockchain::getSocket(){
  return this->_socket;
}

vector<pthread_t> Blockchain::getIdThread(){
  return this->_id;
}
// void* Blockchain::run(void* port){
//
// }
