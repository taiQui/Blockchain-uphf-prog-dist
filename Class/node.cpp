#include "node.hpp"

Node::Node(){

}
Node::Node(string id){
  this->_id = id;
}

Node::~Node(){

}

string Node::getid(){
  return this->_id;
}

void Node::setid(string id){
  this->_id = id;
}

float Node::getCalculatedValue(){
  //for avoid error need to change when Implementation is done
  return *(new float(4.5));
}
