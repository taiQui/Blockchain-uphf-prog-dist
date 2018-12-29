#ifndef node_hpp
#define node_hpp

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <cstdlib>
#include "block.hpp"
#include <vector>
using namespace std;

class Node {

private:
  string _id;
  clock_t timer;
  pthread_t idth;
  vector<int> _socket;
  Block *block;
public:
  vector<pthread_t> _idt;
  Node(string id,vector<int> socket, vector<pthread_t> idt);
  Node(string);
  Node(const Node&);
  ~Node();

  string getid(); //getter
  void setid(string);
  float getCalculatedValue();
  double getTime();
  Block* getblock();
  vector<int> getSocket();
  vector<pthread_t> getIdThread();
  int getSocketByIndex(int);
  void addingThread(pthread_t);
  void *run();
  int getSizeSocket();
  int getSocketAt(int);
  int getSizeThread();
  pthread_t* getThreadAt(int );
  void addingSocket(int);

};


#endif
