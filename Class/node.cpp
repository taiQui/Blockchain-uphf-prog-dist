#include "node.hpp"


Node::Node(string id,vector<int> socket, vector<pthread_t> idt){
  this->_id = id;
  this->_idt = idt;
  this->_socket = socket;
  this->timer = clock();
  this->block = new Block();
}

Node::Node(const Node& node){
  this->_id = node._id;
  this->timer = node.timer;
  this->idth = node.idth;
  this->_socket = node._socket;
  this->_idt = node._idt;
  this->block= node.block;
}

Block* Node::getblock(){
  return this->block;
}

Node::Node(string id){
  this->_id = id;
  this->timer = clock();

}

Node::~Node(){

}

int Node::getSizeThread(){
  return this->_idt.size();
}

pthread_t* Node::getThreadAt(int index){
  return &(this->_idt.at(index));
}

int Node::getSizeSocket(){
  return this->_socket.size();
}

void Node::addingSocket(int sock){
  this->_socket.push_back(sock);
}

int Node::getSocketAt(int index){
  return this->_socket.at(index);
}

void Node::addingThread(pthread_t id){
  this->_idt.push_back(id);
}

string Node::getid(){
  return this->_id;
}

void Node::setid(string id){
  this->_id = id;
}

int Node::getSocketByIndex(int index){
  return this->_socket.at(index);
}

vector<int> Node::getSocket(){
  return this->_socket;
}

vector<pthread_t> Node::getIdThread(){
  return this->_idt;
}

float Node::getCalculatedValue(){
  //for avoid error need to change when Implementation is done
  return *(new float(4.5));
}

double Node::getTime(){
  double duration = (clock() - (this->timer ) / (double) CLOCKS_PER_SEC);
  // cout<<"TIIIIIIIIIIIIIIIIIME"<<endl;
  // cout<<"GET Time : "<<duration<<endl;
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
