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
  vector<string> calculatedValue;
  vector<int> socktorespond;
  int getlength();
  void setlength(int);
  int getSocketByIndex(int);
  vector<int> getSocket();
  vector<pthread_t> getIdThread();
  bool canI;

  Blockchain();
  Blockchain(vector<int> socket, vector<pthread_t> id, int length);
  ~Blockchain();

  int getSizeBlocklist();
  void clear();
  void setBool(bool);
  bool getBool();
  int getSizeCalc();
  int getSizeSockTo();
  int getSocktorespond(int);
  string getCalcvalue(int);
  void addtosocktorespond(int);
  void addtocalcvalue(string);
  vector<int> getsocktorespond();
  vector<string> getcalcvalue();
  void addBlock(Block*);
  void removeBlock(string);
  Block readBlock(int);
  bool checkIndex(int);
  void addingThread(pthread_t);
  void addingSocket(int);
  int getSizeSocket();
  int getSocketAt(int);
  pthread_t* getThreadAt(int);
  int getSizeThread();
  void response(int);
};


#endif
