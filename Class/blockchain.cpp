#include "blockchain.hpp"

Blockchain::Blockchain(){
  this->canI = true;
  this->_bl = new BlockList();
}

Blockchain::Blockchain(vector<int> socket, vector<pthread_t> id, int length){
  this->_bl = new BlockList();
  this->_socket = socket;
  this->_id = id;
  this->_length = length;
  this->canI = true;
}

Blockchain::~Blockchain(){
  delete this->_bl;
}

void Blockchain::addBlock(Block* block){
  this->_bl->addBlock(block);
}

int Blockchain::getSizeBlocklist(){
  return this->_bl->getLength();
}

void Blockchain::removeBlock(string hash){
  this->_bl->removeBlock(hash);
}

int Blockchain::getSizeThread(){
  return this->_id.size();
}

int Blockchain::getSizeSocket(){
  return this->_socket.size();
}

int Blockchain::getSocketAt(int index){
  return this->_socket.at(index);
}

pthread_t* Blockchain::getThreadAt(int index){
  return &(this->_id.at(index));
}

void Blockchain::addingThread(pthread_t id){
  this->_id.push_back(id);
}

void Blockchain::addingSocket(int sock){
  this->_socket.push_back(sock);
}

Block Blockchain::readBlock(int index){
  Block aux = this->_bl->getBlock();
  for( int i = this->_length; i > this->_length-index ;i--){
    aux = *(aux.getInferiorBlock());
  }
  return aux;
}

bool Blockchain::checkIndex(int index){
  return(index >= 0 && index <= this->_length);
}

int Blockchain::getlength(){
  return this->_length;
}

void Blockchain::setlength(int size){
  this->_length = size;
}

void Blockchain::setBool(bool bol){
  this->canI = bol;
}

bool Blockchain::getBool(){
  return this->canI;
}

int Blockchain::getSizeSockTo(){
  return this->socktorespond.size();
}

void Blockchain::clear(){
  this->calculatedValue.clear();
  this->socktorespond.clear();
  // cout<<"2 VECTOR IS CLEAR"<<endl;
}


void Blockchain::responsevoid(int sock){
  char *msg = "sexe";
  std::this_thread::sleep_for(std::chrono::nanoseconds(5));
  std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
  int nb;

  while((nb= send(sock,msg,strlen(msg),0))<= 0){};

  fflush(stdout);
  char hello[1024];
  nb= read(sock,hello,sizeof(hello));
// nb = read(this->getSocktorespond(max),bl,sizeof(bl));
  if(nb > 0){

    // cout<<"EZZ MAMENE : "<<this->_length<<endl;
    while((nb = send(sock,"sex",3,0))<=0){};
  }
}

void Blockchain::response(int max){
  char *msg = "IWANTYOU";
  Block* bl = nullptr;
  std::this_thread::sleep_for(std::chrono::nanoseconds(5));
  std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
  int nb;
  while((nb = send(this->getSocktorespond(max),msg,strlen(msg),0))<=0){};
  fflush(stdout);
  nb = read(this->getSocktorespond(max),bl,sizeof(bl));
// nb = read(this->getSocktorespond(max),bl,sizeof(bl));
  if(nb > 0){
    if(bl == nullptr){
      // cout<<"NULL PTR C NUL SA MERE"<<endl;
    }
    this->addBlock(bl);
    this->calculatedValue.clear();
    this->socktorespond.clear();
    this->canI = true;
    cout<<"ADDING BLOCK TO BLOCKCHAIN size : "<<this->_length<<endl;
    send(this->getSocktorespond(max),"sex",3,0);
  } else {
    cout<<"Failed to add block  "<<endl;
  }
}

int Blockchain::getSizeCalc(){
  return this->calculatedValue.size();
}

void Blockchain::addtocalcvalue(string add){
  this->calculatedValue.push_back(add);
}

string Blockchain::getCalcvalue(int index){
  return this->calculatedValue.at(index);
}

int Blockchain::getSocktorespond(int index){
  return this->socktorespond.at(index);
}

void Blockchain::addtosocktorespond(int sock){
  this->socktorespond.push_back(sock);
}

vector<string> Blockchain::getcalcvalue(){
  return this->calculatedValue;
}

vector<int> Blockchain::getsocktorespond(){
  return this->socktorespond;
}

int Blockchain::getSocketByIndex(int index){
  return this->_socket.at(index);
}

vector<int> Blockchain::getSocket(){
  return this->_socket;
}

vector<pthread_t> Blockchain::getIdThread(){
  return this->_id;
}
// void* Blockchain::run(void* port){
//
// }
