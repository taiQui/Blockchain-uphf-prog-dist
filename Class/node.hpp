#ifndef node_hpp
#define node_hpp

#include <iostream>
#include <string>

using namespace std;

class Node {

private:
  string _id;
  //add timer

public:
  Node();
  Node(string);
  ~Node();

  string getid(); //getter
  void setid(string);
  float getCalculatedValue();

};

#endif
