#include "node.hpp"

void* ChronoNode(void* timer){
  timer = (clock_t*)clock();
}

Node::Node(){
  pthread_create(&this->idth,NULL,ChronoNode,(void*)&(this)->timer);
}

Node::Node(string id){
  this->_id = id;
  pthread_create(&this->idth,NULL,ChronoNode,(void*)&(this)->timer);

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

double Node::getTime(){
  double duration = (clock() - *(this)->timer ) / (double) CLOCKS_PER_SEC;
  return duration;
}

void* Node::run(){
  long int decompte = 5;
  while(true){
    if(this->getTime() >= 5 ){
      //send to blockchain getCalculatedValue
      decompte+=5;
    }
  }
}
