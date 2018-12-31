#include "main.hpp"


struct args_nd {
  int sock;
  int choix;
  int whoami;
};
//Creating first airport
Node* airport1 = new Node("A-blagnac");
//Creating second airport
Node* airport2 = new Node("A-lesquin");
//Creating last airport
Node* airport3 = new Node("A-roissy");
//Creating blockchain
Blockchain* bc = new Blockchain();

int main(){

  pthread_t tabID[4];
  pthread_create(&tabID[0],NULL,runNode1,NULL);
  pthread_create(&tabID[1],NULL,runNode2,(void*)&airport2);
  pthread_create(&tabID[2],NULL,runNode3,(void*)&airport3);
  pthread_create(&tabID[3],NULL,runBlockchain,NULL);
  pthread_join(tabID[0],NULL);
  pthread_join(tabID[1],NULL);
  pthread_join(tabID[2],NULL);
  pthread_join(tabID[3],NULL);
  pthread_exit(&tabID[0]);
  pthread_exit(&tabID[1]);
  pthread_exit(&tabID[2]);
  pthread_exit(&tabID[3]);
}


void* runNode1(void* vide){
  long int decompte = 5;
  while(true){
    long int decompte = 0;
    int Sock_server;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    // Creating socket file descriptor
    if ((Sock_server = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    // Forcefully attaching socket to the port 8080
     if (setsockopt(Sock_server, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                   &opt, sizeof(opt)))
     {
         perror("setsockopt");
         exit(EXIT_FAILURE);
     }
     address.sin_family = AF_INET;
     address.sin_addr.s_addr = INADDR_ANY;
     address.sin_port = htons(AIRPORT1);
     // Forcefully attaching socket to the port 8080

      if (bind(Sock_server, (struct sockaddr *)&address,
                                   sizeof(address))<0)
      {
          perror("bind failed");
          exit(EXIT_FAILURE);
      }
      if (listen(Sock_server, 10) < 0)
      {
          perror("listen");
          exit(EXIT_FAILURE);
      }
      cout << "Airport1 beginning thread"<<endl;
      // int a2 = connecte(AIRPORT2);
      // cout<<"1 : "<<a2<<endl;
      // if(a2 > 0) {
      // struct args_nd arguments1;
      // arguments1.sock = a2;
      // arguments1.choix = 2;
      // arguments1.whoami =1;
      //   pthread_t id;
      //   pthread_create(&id,NULL,runListen,(void*)&arguments1);
      // }
      // int a3 = connecte(AIRPORT3);
      // cout<<"2 : "<<a3<<endl;
      // if(a3 > 0 ){
      //     struct args_nd arguments2;
      //     arguments2.sock = a3;
      //     arguments2.choix = 3;
      //     arguments2.whoami =1;
      //   pthread_t id;
      //   pthread_create(&id,NULL,runListen,(void*)&arguments2);
      // }

      int blockc = connecte(BLOCKCHAIN);
      cout<<"socket airport 1 to blockchain : "<<blockc<<";"<<endl;
      if(blockc > 0){
        struct args_nd arguments3;
        arguments3.sock = blockc;
        arguments3.choix = 4;
        arguments3.whoami =1;
        pthread_t id;
        pthread_create(&id,NULL,runListen,(void*)&arguments3);
      }


      sleep(1);
    while(1){
      int new_sock;

      if ((new_sock = accept(Sock_server, (struct sockaddr *)&address,
                        (socklen_t*)&addrlen))<0)
     {
         perror("accept");
         exit(EXIT_FAILURE);
     } else {
       // cout<<"----------------EZ----------\n";
       // cout<<"TEST APRES ACCEPT"<<endl;
       airport1->addingSocket(new_sock);
       // cout<<"RUNNODE TEST 1"<<endl;
       pthread_t threadid;
       // cout<<"RUNNODE TEST 2"<<endl;
       // cout<<"--------------------------------\nVALUE : "<<airport1->getSizeThread()<<endl;
       airport1->addingThread(threadid);
       // cout<<"--------------------------------\nVALUE : "<<airport1->getSizeThread()<<endl;
       // cout<<"RUNNODE TEST 3"<<endl;
       struct args_nd arguments;
       // cout<<"RUNNING TEST 4"<<endl;
       arguments.sock = new_sock;
       arguments.choix = 1;
       arguments.whoami =1;
       // cout<<"RUNNODE SIZE :------------- "<<airport1->getSizeThread()<<endl;
       pthread_create(airport1->getThreadAt((airport1->getSizeThread()-1)),NULL,runListen,(void*)&arguments);
       // cout<<"RUNNING TEST 5"<<endl;
     }
    }
  }
}
void* runNode2(void* vide){
  long int decompte = 5;
  while(true){
    long int decompte = 0;
    int Sock_server;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    // Creating socket file descriptor
    if ((Sock_server = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    // Forcefully attaching socket to the port 8080
     if (setsockopt(Sock_server, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                   &opt, sizeof(opt)))
     {
         perror("setsockopt");
         exit(EXIT_FAILURE);
     }
     address.sin_family = AF_INET;
     address.sin_addr.s_addr = INADDR_ANY;
     address.sin_port = htons(AIRPORT2);
     // Forcefully attaching socket to the port 8080
      if (bind(Sock_server, (struct sockaddr *)&address,
                                   sizeof(address))<0)
      {
          perror("bind failed");
          exit(EXIT_FAILURE);
      }
      if (listen(Sock_server, 10) < 0)
      {
          perror("listen");
          exit(EXIT_FAILURE);
      }
      cout << "Airport 2 beginning thread"<<endl;
      // int a2 = connecte(AIRPORT1);
      // cout<<"1 : "<<a2<<endl;
      // if(a2 > 0) {
      // struct args_nd arguments1;
      // arguments1.sock = a2;
      // arguments1.choix = 1;
      // arguments1.whoami =2;
      //   pthread_t id;
      //   pthread_create(&id,NULL,runListen,(void*)&arguments1);
      // }
      // int a3 = connecte(AIRPORT3);
      // cout<<"2 : "<<a3<<endl;
      // if(a3 > 0 ){
      //     struct args_nd arguments2;
      //     arguments2.sock = a3;
      //     arguments2.choix = 3;
      //     arguments2.whoami =2;
      //   pthread_t id;
      //   pthread_create(&id,NULL,runListen,(void*)&arguments2);
      // }
      std::this_thread::sleep_for(std::chrono::nanoseconds(5));
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(3));
      int blockc = connecte(BLOCKCHAIN);
      cout<<"socket airport 2 to blockchain : "<<blockc<<";"<<endl;
      if(blockc > 0){
        struct args_nd arguments3;
        arguments3.sock = blockc;
        arguments3.choix = 4;
        arguments3.whoami =2;
        pthread_t id;
        pthread_create(&id,NULL,runListen,(void*)&arguments3);
      }


      sleep(1);
    while(1){
      int new_sock;

      if ((new_sock = accept(Sock_server, (struct sockaddr *)&address,
                        (socklen_t*)&addrlen))<0)
     {
         perror("accept");
         exit(EXIT_FAILURE);
     } else {
       // cout<<"----------------EZ----------\n";
       // cout<<"TEST APRES ACCEPT"<<endl;
       airport2->addingSocket(new_sock);
       // cout<<"RUNNODE TEST 1"<<endl;
       pthread_t threadid;
       // cout<<"RUNNODE TEST 2"<<endl;
       // cout<<"--------------------------------\nVALUE : "<<airport1->getSizeThread()<<endl;
       airport2->addingThread(threadid);
       // cout<<"--------------------------------\nVALUE : "<<airport1->getSizeThread()<<endl;
       // cout<<"RUNNODE TEST 3"<<endl;
       struct args_nd arguments;
       // cout<<"RUNNING TEST 4"<<endl;
       arguments.sock = new_sock;
       arguments.choix = 2;
       arguments.whoami =2;
       // cout<<"RUNNODE SIZE :------------- "<<airport1->getSizeThread()<<endl;
       pthread_create(airport2->getThreadAt((airport2->getSizeThread()-1)),NULL,runListen,(void*)&arguments);
       // cout<<"RUNNING TEST 5"<<endl;
     }
    }
  }
}
void* runNode3(void* vide){
  long int decompte = 5;
  while(true){
    long int decompte = 0;
    int Sock_server;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    // Creating socket file descriptor
    if ((Sock_server = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    // Forcefully attaching socket to the port 8080
     if (setsockopt(Sock_server, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                   &opt, sizeof(opt)))
     {
         perror("setsockopt");
         exit(EXIT_FAILURE);
     }
     address.sin_family = AF_INET;
     address.sin_addr.s_addr = INADDR_ANY;
     address.sin_port = htons(AIRPORT2);
     // Forcefully attaching socket to the port 8080
      if (bind(Sock_server, (struct sockaddr *)&address,
                                   sizeof(address))<0)
      {
          perror("bind failed");
          exit(EXIT_FAILURE);
      }
      if (listen(Sock_server, 10) < 0)
      {
          perror("listen");
          exit(EXIT_FAILURE);
      }
      cout << "Airport 3 beginning thread"<<endl;
      // int a2 = connecte(AIRPORT1);
      // cout<<"1 : "<<a2<<endl;
      // if(a2 > 0) {
      // struct args_nd arguments1;
      // arguments1.sock = a2;
      // arguments1.choix = 1;
      // arguments1.whoami =3;
      //   pthread_t id;
      //   pthread_create(&id,NULL,runListen,(void*)&arguments1);
      // }
      // int a3 = connecte(AIRPORT2);
      // cout<<"2 : "<<a3<<endl;
      // if(a3 > 0 ){
      //     struct args_nd arguments2;
      //     arguments2.sock = a3;
      //     arguments2.choix = 2;
      //     arguments2.whoami =3;
      //   pthread_t id;
      //   pthread_create(&id,NULL,runListen,(void*)&arguments2);
      // }
      std::this_thread::sleep_for(std::chrono::nanoseconds(5));
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(6));
      int blockc = connecte(BLOCKCHAIN);
      cout<<"socket airport 3 to blockchain: "<<blockc<<";"<<endl;
      if(blockc > 0){
        struct args_nd arguments3;
        arguments3.sock = blockc;
        arguments3.choix = 4;
        arguments3.whoami =3;
        pthread_t id;
        pthread_create(&id,NULL,runListen,(void*)&arguments3);
      }

      // cout<<"END CONNECT 1 "<<endl;
      sleep(1);
    while(1){
      int new_sock;

      if ((new_sock = accept(Sock_server, (struct sockaddr *)&address,
                        (socklen_t*)&addrlen))<0)
     {
         perror("accept");
         exit(EXIT_FAILURE);
     } else {
       // cout<<"----------------EZ----------\n";
       // cout<<"TEST APRES ACCEPT"<<endl;
       airport3->addingSocket(new_sock);
       // cout<<"RUNNODE TEST 1"<<endl;
       pthread_t threadid;
       // cout<<"RUNNODE TEST 2"<<endl;
       // cout<<"--------------------------------\nVALUE : "<<airport1->getSizeThread()<<endl;
       airport3->addingThread(threadid);
       // cout<<"--------------------------------\nVALUE : "<<airport1->getSizeThread()<<endl;
       // cout<<"RUNNODE TEST 3"<<endl;
       struct args_nd arguments;
       // cout<<"RUNNING TEST 4"<<endl;
       arguments.sock = new_sock;
       arguments.choix = 3;
       arguments.whoami =3;
       // cout<<"RUNNODE SIZE :------------- "<<airport1->getSizeThread()<<endl;
       pthread_create(airport3->getThreadAt((airport3->getSizeThread()-1)),NULL,runListen,(void*)&arguments);
       // cout<<"RUNNING TEST 5"<<endl;
     }
    }
  }
}

void* runListen(void* args){
  long int decompte = 5;
  int nb;
  char buffer[1024] = {0};
  struct args_nd test = *(struct args_nd*)args;
  Node* aux = NULL;
  Blockchain* aux2 = NULL;
  cout<<"In thread listenig socket from Airport "<<test.whoami<<endl;
  // switch(test.choix){
  //   case 1:
  //     aux = new Node(*airport1);
  //     break;
  //   case 2:
  //     aux = new Node(*airport2);
  //     break;
  //   case 3:
  //     aux = new Node(*airport3);
  //     break;
  //   case 4:
  //     aux2 = bc;
  // }
  if(aux2 == NULL) {
    // cout <<"RUN LISTEN : struct : "<<test.sock<<";"<<endl;
    // cout<<"RUN LISTEN : TIME "<<airport1->getTime()<<endl;
    // cout<<"RUN LISTEN : debut"<<endl;
  }
  int tm = 0;
  int ds = 10;
  clock_t start = clock();
  while(true){
      // if(((clock() - start ) / (double) CLOCKS_PER_SEC) > ds ) {
      std::this_thread::sleep_for(std::chrono::nanoseconds(5));
      std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(10));
        // cout<<"RUNLISTEN TEST 3 -----------------------------\n------------------------------\n-----------------------"<<endl;
        ds+=10;
        tm+=10;
        srand(time(NULL));
        int randomnumber = (rand()%(10000-0))+0;
        string msg = to_string(randomnumber);
        string sender;
        switch(test.whoami){
          case 1:
            sender = "1-";
            switch(test.choix){
              case 1:
                cout<<"airport 1 send : "<<msg<<" to airport 1"<<endl;

                break;
              case 2:
                cout<<"airport 1 send : "<<msg<<" to airport 2"<<endl;
                break;
              case 3:
                cout<<"airport 1 send : "<<msg<<" to airport 3"<<endl;
                break;
              case 4:
                cout<<"airport 1 send : "<<msg<<" to blockchain"<<endl;
                break;
            }
            break;
          case 2:
          sender = "2-";
          switch(test.choix){
            case 1:
              cout<<"airport 2 send : "<<msg<<" to airport 1"<<endl;

              break;
            case 2:
              cout<<"airport 2 send : "<<msg<<" to airport 2"<<endl;
              break;
            case 3:
              cout<<"airport 2 send : "<<msg<<" to airport 3"<<endl;
              break;
            case 4:
              cout<<"airport 2 send : "<<msg<<" to blockchain"<<endl;
              break;
          }
            break;
          case 3:
          sender="3-";
          switch(test.choix){
            case 1:
              cout<<"airport 3 send : "<<msg<<" to airport 1"<<endl;

              break;
            case 2:
              cout<<"airport 3 send : "<<msg<<" to airport 2"<<endl;
              break;
            case 3:
              cout<<"airport 3 send : "<<msg<<" to airport 3"<<endl;
              break;
            case 4:
              cout<<"airport 3 send : "<<msg<<" to blockchain"<<endl;
              break;
          }
            break;
          case 4:
          sender="4-";
          switch(test.choix){
            case 1:
              cout<<"blockchain send : "<<msg<<" to airport 1"<<endl;

              break;
            case 2:
              cout<<"blockchain send : "<<msg<<" to airport 2"<<endl;
              break;
            case 3:
              cout<<"blockchain send : "<<msg<<" to airport 3"<<endl;
              break;
            case 4:
              cout<<"blockchain send : "<<msg<<" to blockchain"<<endl;
              break;
          }
            break;
        }
        msg = sender+msg;
        const char* msgtosend = msg.c_str();
        fflush(stdout);
        int nb;
        int nbr;
        while((nb = send(test.sock,msgtosend,strlen(msgtosend),0))<=0){};
        // fflush(stdout);
         // while((nb= read(test.sock,buffer,strlen(buffer)))<=0){};
          nb = read(test.sock,buffer,strlen(buffer));

        // cout<<"APRES AVOIR LUS"<<endl;
        if(nb > 0){
          switch(test.whoami){
            case 1:
              cout<<"airport1 receive : "<<buffer<<endl;
              break;
            case 2:
              cout<<"airport2 receive : "<<buffer<<endl;
              break;
            case 3:
              cout<<"airport3 receive : "<<buffer<<endl;
              break;
          }

          string s(buffer);
          std::this_thread::sleep_for(std::chrono::nanoseconds(5));
          std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
          if(s == "IWANTYOU"){
            fflush(stdout);

            switch(test.whoami){
              case 1:
                while((nb = send(test.sock,airport1->getblock(),sizeof(airport1->getblock()),0))<=0){};
                break;
              case 2:
                while((nb = send(test.sock,airport2->getblock(),sizeof(airport2->getblock()),0))<=0){};
                break;
              case 3:
                while((nb = send(test.sock,airport3->getblock(),sizeof(airport3->getblock()),0))<=0){};
                break;
            }
            read(test.sock,buffer,strlen(buffer));
            // std::this_thread::sleep_for(std::chrono::nanoseconds(5));
            // std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
          } else {
            char hello[1024];
            char *hel = "YOLO";
            while((nb = send(test.sock,hel,strlen(hel),0))<=0){};
            read(test.sock,buffer,strlen(buffer));
          }
        } else {
          // cout<<"J'AI RIEN LUS BATARD"<<endl;
        }
        start = clock();
      // }
      // cout<<"RUNLISTEN TEST 4"<<endl;


      // send(test.sock,"hello",4,0);
  }
}

void* runBlockchain(void* vide){
  long int decompte = 5;
  while(true){
    long int decompte = 0;
    int Sock_server;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    // Creating socket file descriptor
    if ((Sock_server = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(Sock_server, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
      &opt, sizeof(opt)))
      {
        perror("setsockopt");
        exit(EXIT_FAILURE);
      }
    // Sock_server = nonBlockingSocket(Sock_server);
    // Forcefully attaching socket to the port 8080


     address.sin_family = AF_INET;
     address.sin_addr.s_addr = INADDR_ANY;
     address.sin_port = htons(BLOCKCHAIN);
     // Forcefully attaching socket to the port 8080
      if (bind(Sock_server, (struct sockaddr *)&address,
                                   sizeof(address))<0)
      {
          perror("bind failed");
          exit(EXIT_FAILURE);
      }
      if (listen(Sock_server, 10) < 0)
      {
          perror("listen");
          exit(EXIT_FAILURE);
      }
      cout << "Blockchain beginning Thread "<<endl;

      // int a2 = connecte(AIRPORT1);
      // cout << "4  : "<<a2 <<";"<< endl;
      // if(a2 > 0) {
      //   struct args_nd arguments1;
      //   arguments1.sock = a2;
      //   arguments1.choix = 1;
      //   pthread_t tid;
      //   cout<<"BC : AVANT THREAD"<<endl;
      //   pthread_create(&tid,NULL,runClient,(void*)&arguments1);
      // } else {
      //   cout<<"BC : FAIL"<<endl;
      // }
      // int a3 = connecte(AIRPORT2);
      // cout <<"4  : "<< a3 << endl;
      // if(a3 > 0 ){
      //   pthread_t id;
      //   pthread_create(&id,NULL,runClient,(void*)&a3);
      // }
      // int blockc = connecte(AIRPORT3);
      // cout << "4  : "<<blockc << endl;
      // if(blockc > 0){
      //   pthread_t id;
      //   pthread_create(&id,NULL,runClient,(void*)&blockc);
      // }
      // cout<<"END CONNECT 4 "<<endl;


    while(1){
      int new_sock;
      if ((new_sock = accept(Sock_server, (struct sockaddr *)&address,
                        (socklen_t*)&addrlen))<=0)
     {
         // perror("accept");
         // exit(EXIT_FAILURE);
     } else {
       // cout<<"runblockchain AVANT PUSH"<<endl;
       bc->addingSocket(new_sock);
       // cout<<"runblockchain apres push"<<endl;
       pthread_t threadid;
       // cout<<"runblockchain avant push 2"<<endl;
       bc->addingThread(threadid);
       // cout<<"runblockchain avant create"<<endl;
       // cout<<"runblockchain SIZE : "<<airport1->getSizeSocket()<<endl;

       pthread_create(bc->getThreadAt((bc->getSizeThread())-1),NULL,runClient,(void*)&new_sock);
       // cout<<"runblockchain apres create"<<endl;

     }
    }
  }
}


int connecte(int port){
  struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    return sock;
}

vector<string> split(string str,char charactosplit){
  string aux = "";
  vector<string> tab;

  for(int i = 0;i < str.size();i++){
    // cout<<"AUX : "<<aux<<endl;
    // cout<<"str : "<<str[i]<<" --- charac : "<<charactosplit<<endl;
    if(str[i] == charactosplit){
      tab.push_back(aux);
      aux.clear();
    } else {
      aux += str[i];
    }

  }
  tab.push_back(aux);
  // cout<<"start-----"<<endl;
  // for(int i = 0; i < tab.size();i++){
    // cout<<tab.at(i)<<endl;
  // }
  // cout<<"---end"<<endl;
  return(tab);
}

bool ispresent(vector<string> str,string search){

  for(int i = 0; i < str.size(); i++){
    string a = split(str.at(i),'-').at(0);
    if(a == search){
      return true;
    }
  }
  return false;
}

int getmax(vector<string> str){
  int max = -1;
  int index = -1;
  // cout<<"-------END"<<endl;
  for(int i = 0; i < str.size();i++){
    if(stoi(split(str.at(i),'-').at(1)) > max ){
      max = stoi(split(str.at(i),'-').at(1));
      index = i;
    }
  }
  // cout<<"GET MAAAAAAAAAAAAAAX : "<<index<<endl;
  return index;
}

void * runClient(void* args){
  // cout<<"RUN CLIENT : entrée"<<endl;
  int nb=0;
  char buffer[1024] = {0};
  // cout<<"RUN CLIENT : avant struct"<<endl;
  // cout<<"RUN CLIENT : struct  : "<<*(int*)args<<endl;
  // cout<<"runClient : apres struct  "<<endl;
  cout<<"In Thread listening from blockchain"<<endl;
  // *(int*)args = nonBlockingSocket(*(int*)args);
  while(1){
    // cout <<"run Client : avant read"<<endl;
    nb = read( *(int*)args , buffer, 1024);
    // cout<<"RUN CLIENT : apres reead"<<endl;
    if(nb <= 0){
      printf("buffer containt nothing\n");
    } else {
      printf("message receive from blockchain : %s\n",buffer);
      string s(buffer);
      // cout<<"HELLOOOOOO : "<<s<<endl;
      bool lol = false;
      for(int i = 0; i < s.length();i++){
        if(s[i] == '-'){
          lol = true;
        }
      }
      if(lol){
        string splitted = split(s,'-').at(0);
        // cout<<"TAAAIIIIILLLLLLLLE  EEEE : "<<bc->getSizeCalc()<<endl;
        if(!ispresent(bc->getcalcvalue(),splitted)){
          // cout<<"TEST 1"<<endl;
          if(bc->getBool() == true){
            bc->setBool(false);
          } else {
            while(bc->getBool()== false){}
            bc->setBool(false);
          }
          bc->addtocalcvalue(s);
          bc->addtosocktorespond(*(int*)args);
          bc->setBool(true);
        }
        // cerr<<"RHELLO MAMEN"<<endl;
        // cout<<"TAIIIIIIIIIIIIIIILLLLLLLLEEEEEE : "<<bc->getSizeSockTo()<<endl;
        // cout<<"AIEAIEAIE : "<<getmax(bc->getcalcvalue())<<endl;
        if(bc->getSizeSockTo()>=3){
          std::this_thread::sleep_for(std::chrono::nanoseconds(5));
          std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
          if(*(int*)args == bc->getSocktorespond(getmax(bc->getcalcvalue()))){
            fflush(stdout);
            cout<<"---------------\n-----------------\nFIND BLOCK TO ADD \n------------------\n-----------------------\n";
            // cout<<"MAX TESTED : "<<getmax(bc->getcalcvalue())<<endl;

            bc->response(getmax(bc->getcalcvalue()));
            bc->clear();
            // cout<<"SIZE OF BLOCKCHAIN : "<<b ¡:c->getSizeBlocklist()<<endl;
          } else {
            bc->responsevoid(*(int*)args);
          }
        } else {
          const char* rep = "RECEIVE_OK!";
          // cout<<"REPOOOOOONDS GROS FDP"<<endl;
          std::this_thread::sleep_for(std::chrono::nanoseconds(5));
          std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
          // send(*(int*)args,rep,strlen(rep),0);
          bc->responsevoid(*(int*)args);
        }
        // std::this_thread::sleep_for(std::chrono::nanoseconds(5));
        // std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
        // send(*(int*)args,"hello",4,0);

      }
    }
    // cout<<"RUN CLIENT : fin"<<endl;
  }
}
