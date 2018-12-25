#ifndef node_hpp
#define node_hpp

#include <iostream>
#include <string>
#include <ctime>
#include <pthread.h>
using namespace std;

class Node {

private:
  string _id;
  clock_t *timer;
  pthread_t idth;
public:
  Node();
  Node(string);
  ~Node();

  string getid(); //getter
  void setid(string);
  float getCalculatedValue();
  double getTime();

  void *run();

};


#endif
