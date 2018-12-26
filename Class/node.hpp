#ifndef node_hpp
#define node_hpp

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <cstdlib>
#include <vector>
using namespace std;

class Node {

private:
  string _id;
  clock_t *timer;
  pthread_t idth;
  vector<int> _socket;
  vector<pthread_t> _idt;
public:
  Node();
  Node(string);
  ~Node();

  string getid(); //getter
  void setid(string);
  float getCalculatedValue();
  double getTime();
  vector<int> getSocket();
  vector<pthread_t> getIdThread();
  int getSocketByIndex(int);

  void *run();

};


#endif
