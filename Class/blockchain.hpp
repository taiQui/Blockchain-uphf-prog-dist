#ifndef blockchain_hpp
#define blockchain_hpp

#include <iostream>
#include <string>
#include "block.hpp"
#include <ctime>
#include "blocklist.hpp"
#include "../MAIN/headers.hpp"
class Blockchain {

private:
  BlockList* _bl;

  vector<int>_socket;
  vector<pthread_t> _id;
  int _length;
public:
  int getlength();
  void setlength(int);
  int getSocketByIndex(int);
  vector<int> getSocket();
  vector<pthread_t> getIdThread();

  Blockchain();
  Blockchain(vector<int> socket, vector<pthread_t> id, int length);
  ~Blockchain();

  void addBlock(Block*);
  void removeBlock(string);
  Block readBlock(int);
  bool checkIndex(int);


};


#endif
