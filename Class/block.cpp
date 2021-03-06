#include "block.hpp"

void *ChronoBlock(void* timer){
  timer = (clock_t*)clock();

}

Block::Block(){
  int error = pthread_create(&this->idth, NULL, ChronoBlock, (void*)&(this)->_timer);

}

Block::Block(string hash,Block* inf, int length, vector<Transaction> tr){
  this->_hash = hash;
  this->_inferiorBlock = inf;
  this->_length = length;
  this->_transactionList = tr;
  pthread_create(&this->idth, NULL, ChronoBlock, (void*)&(this)->_timer);

}

Block::~Block(){
  pthread_exit(&this->idth);

}

string Block::getHash(){
  return this->_hash;
}

// Here '_inferiorBlock' is a pointer so we need to dereference it to access his value
Block* Block::getInferiorBlock(){
  return this->_inferiorBlock;
}

int Block::getLength(){
  return this->_length;
}

void Block::setHash(string hash){
  this->_hash = hash;
}

void Block::setInferiorBlock(Block* block){
  this->_inferiorBlock = block;
}

vector<Transaction> Block::getAllList(){
  return this->_transactionList;
}

void Block::setAllList(vector<Transaction> v){
    this->_transactionList = v;
}

vector<Transaction> Block::getTransactionByType(int type){
  vector<Transaction> tab ;
  for( unsigned i = 0 ; i < this->_transactionList.size() ; i++){
    if(this->_transactionList.at(i).gettype() == type){
      tab.push_back(this->_transactionList.at(i));
    }
  }
  return tab;
}

bool Block::checkIndex(unsigned int index){
  return(index >= 0 && index <= this->_transactionList.size());
}

Transaction Block::getTransactionByIndex(unsigned int index){
    return this->_transactionList.at(index);
}

void Block::addTransaction(Transaction transac){
  this->_transactionList.push_back(transac);
}

double Block::getTime(){
  double duration = (clock() - *(this)->_timer ) / (double) CLOCKS_PER_SEC;
  return duration;
}
