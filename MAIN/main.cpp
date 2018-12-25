#include "main.hpp"

int main(){
	//Creating first airport
  Node* airport1 = new Node("A-blagnac");
  //Creating second airport
  Node* airport2 = new Node("A-lesquin");
  //Creating last airport
  Node* airport3 = new Node("A-roissy");
  //Creating blockchain
  Blockchain* bc = new Blockchain();

  pthread_t tabID[4];
  pthread_create(&tabID[0],NULL,runNode,(void*)&airport1);
  pthread_create(&tabID[1],NULL,runNode,(void*)&airport2);
  pthread_create(&tabID[2],NULL,runNode,(void*)&airport3);
  pthread_create(&tabID[3],NULL,runBlockchain,(void*)&bc);
  pthread_join(tabID[0],NULL);
  pthread_join(tabID[1],NULL);
  pthread_join(tabID[2],NULL);
  pthread_join(tabID[3],NULL);
  pthread_exit(&tabID[0]);
  pthread_exit(&tabID[1]);
  pthread_exit(&tabID[2]);
  pthread_exit(&tabID[3]);
}

void* runNode(void* node){
  long int decompte = 5;
  while(true){
    if((*(Node*)node).getTime() >= 5 ){
      //send to blockchain getCalculatedValue
      decompte+=5;
    }
  }
}

void* runBlockchain(void* bc){
  long int decompte = 5;
  while(true){
    //listen
  }
}
