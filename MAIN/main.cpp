#include "main.hpp"


struct args_nd {
  int sock;
  int choix;
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
  // pthread_create(&tabID[1],NULL,runNode2,(void*)&airport2);
  // pthread_create(&tabID[2],NULL,runNode3,(void*)&airport3);
  pthread_create(&tabID[3],NULL,runBlockchain,NULL);
  pthread_join(tabID[0],NULL);
  // pthread_join(tabID[1],NULL);
  // pthread_join(tabID[2],NULL);
  pthread_join(tabID[3],NULL);
  pthread_exit(&tabID[0]);
  // pthread_exit(&tabID[1]);
  // pthread_exit(&tabID[2]);
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
      cout << "TEST NODE 1"<<endl;
      // int a2 = connecte(AIRPORT2);
      // cout<<"1 : "<<a2<<endl;
      // if(a2 > 0) {
      // struct args_nd arguments1;
      // arguments.sock = a2;
      // arguments.bc = &(*(Node*)bc);
      //   pthread_t id;
      //   pthread_create(&id,NULL,runListen,(void*)&arguments1);
      // }
      // int a3 = connecte(AIRPORT3);
      // cout<<"2 : "<<a3<<endl;
      // if(a3 > 0 ){
          // struct args_nd arguments2;
          // arguments.sock = a3;
          // arguments.bc = &(*(Node*)bc);
      //   pthread_t id;
      //   pthread_create(&id,NULL,runListen,(void*)&arguments2);
      // }
      int blockc = connecte(BLOCKCHAIN);
      cout<<"1 : "<<blockc<<";"<<endl;
      if(blockc > 0){
        struct args_nd arguments3;
        arguments3.sock = blockc;
        arguments3.choix = 4;
        pthread_t id;
        pthread_create(&id,NULL,runListen,(void*)&arguments3);
      }

      cout<<"END CONNECT 1 "<<endl;
      sleep(1);
    while(1){
      int new_sock;
      if ((new_sock = accept(Sock_server, (struct sockaddr *)&address,
                        (socklen_t*)&addrlen))<0)
     {
         perror("accept");
         exit(EXIT_FAILURE);
     }
     cout<<"TEST APRES ACCEPT"<<endl;
      airport1->getSocket().push_back(new_sock);
      pthread_t threadid;
      airport1->getIdThread().push_back(threadid);
      struct args_nd arguments;
      arguments.sock = new_sock;
      arguments.choix = 1;
      pthread_create(&airport1->getIdThread().at(airport1->getIdThread().size()-1),NULL,runListen,(void*)&arguments);
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


      cout << "TEST NODE 2"<<endl;
      int a2 = connecte(AIRPORT1);
      cout<<"2  : " <<a2 << endl;
      if(a2 > 0) {
        pthread_t id;
        pthread_create(&id,NULL,runListen,(void*)&a2);
      }
      int a3 = connecte(AIRPORT3);
      cout<<"2  : " <<a3 << endl;
      if(a3 > 0 ){
        pthread_t id;
        pthread_create(&id,NULL,runListen,(void*)&a3);
      }
      int blockc = connecte(BLOCKCHAIN);
      cout << "2  : "<<blockc << endl;
      if(blockc > 0){
        pthread_t id;
        pthread_create(&id,NULL,runListen,(void*)&blockc);
      }
      cout<<"END CONNECT 2 "<<endl;
      sleep(1);
    while(1){
      int new_sock;
      if ((new_sock = accept(Sock_server, (struct sockaddr *)&address,
                        (socklen_t*)&addrlen))<0)
     {
         perror("accept");
         exit(EXIT_FAILURE);
     }
      airport2->getSocket().push_back(new_sock);
      pthread_t threadid;
      airport2->getIdThread().push_back(threadid);
      struct args_nd arguments;
      arguments.sock = new_sock;
      arguments.choix = 2;
      pthread_create(&airport2->getIdThread().at(airport2->getSocket().size()-1),NULL,runListen,(void*)&arguments);
    }
  }
}
void* runNode3(void* vide){
  // long int decompte = 5;
  // while(true){
  //   long int decompte = 0;
  //   int Sock_server;
  //   struct sockaddr_in address;
  //   int opt = 1;
  //   int addrlen = sizeof(address);
  //   // Creating socket file descriptor
  //   if ((Sock_server = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  //   {
  //       perror("socket failed");
  //       exit(EXIT_FAILURE);
  //   }
  //   // Forcefully attaching socket to the port 8080
  //    if (setsockopt(Sock_server, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
  //                                                  &opt, sizeof(opt)))
  //    {
  //        perror("setsockopt");
  //        exit(EXIT_FAILURE);
  //    }
  //    address.sin_family = AF_INET;
  //    address.sin_addr.s_addr = INADDR_ANY;
  //    address.sin_port = htons(AIRPORT3);
  //    // Forcefully attaching socket to the port 8080
  //     if (bind(Sock_server, (struct sockaddr *)&address,
  //                                  sizeof(address))<0)
  //     {
  //         perror("bind failed");
  //         exit(EXIT_FAILURE);
  //     }
  //     if (listen(Sock_server, 10) < 0)
  //     {
  //         perror("listen");
  //         exit(EXIT_FAILURE);
  //     }
  //     cout << "TEST NODE 3"<<endl;
  //
  //     int a2 = connecte(AIRPORT1);
  //     cout << "3  : "<<a2 << endl;
  //     if(a2 > 0) {
  //       pthread_t id;
  //       pthread_create(&id,NULL,runListen,(void*)&a2);
  //     }
  //     int a3 = connecte(AIRPORT2);
  //     cout <<"3  : "<< a3 << endl;
  //     if(a3 > 0 ){
  //       pthread_t id;
  //       pthread_create(&id,NULL,runListen,(void*)&a3);
  //     }
  //     int blockc = connecte(BLOCKCHAIN);
  //     cout << "3  : "<<blockc << endl;
  //     if(blockc > 0){
  //       pthread_t id;
  //       pthread_create(&id,NULL,runListen,(void*)&blockc);
  //     }
  //     cout<<"END CONNECT 2 "<<endl;
  //     sleep(1);
  //   while(1){
  //     int new_sock;
  //     if ((new_sock = accept(Sock_server, (struct sockaddr *)&address,
  //                       (socklen_t*)&addrlen))<0)
  //    {
  //        perror("accept");
  //        exit(EXIT_FAILURE);
  //    }
  //     airport3->getSocket().push_back(new_sock);
  //     pthread_t threadid;
  //     airport3->getIdThread().push_back(threadid);
  //     struct args_nd arguments;
  //     arguments.sock = new_sock;
  //     arguments.choix = 3;
  //     pthread_create(&airport3->getIdThread().at(airport3->getSocket().size()-1),NULL,runListen,(void*)&arguments);
  //   }
  // }
}

void* runListen(void* args){
  long int decompte = 5;
  int nb;
  char buffer[1024] = {0};
  struct args_nd test = *(struct args_nd*)args;
  Node* aux = NULL;
  Blockchain* aux2 = NULL;
  switch(test.choix){
    case 1:
      aux = airport1;
      break;
    case 2:
      aux = airport2;
      break;
    case 3:
      aux = airport3;
      break;
    case 4:
      aux2 = bc;
  }
  if(aux2 == NULL) {
    cout <<"RUN LISTEN : struct : "<<test.sock<<";"<<endl;
    cout<<"RUN LISTEN : TIME "<<aux->getTime()<<endl;
    cout<<"RUN LISTEN : debut"<<endl;
  }
  int tm = 0;
  int ds = 5;
  while(true){
    if(aux2 == NULL){
      int randomnumber = (rand()%(10000-0))+0;
      cout<<"RUN LISTEN : apres ranom"<<endl;
      cout<<"RUN LISTEN : TIME "<<(aux->getTime())<<endl;
      if(aux->getTime() >= 5 ){
        cout<<"RUN LISTEN : avant str to char"<<endl;
        const char* msg = to_string(randomnumber).c_str();
        cout<<"RUN LISTEN : apres str to char"<<endl;
        send(test.sock,msg,sizeof(msg),0);
        cout<<"RUN LISTEN : apres envoie"<<endl;
        decompte+=5;
      }
      cout<<"RUN LISTEN : fin"<<endl;
    } else {

      clock_t start = clock();

      if(((clock() - start ) / (double) CLOCKS_PER_SEC) > ds ) {
        ds+=5;
        tm+=5;
        int randomnumber = (rand()%(10000-0))+0;
        const char* msg = to_string(randomnumber).c_str();
        send(test.sock,msg,sizeof(msg),0);
      }



    }
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
    // Forcefully attaching socket to the port 8080
     if (setsockopt(Sock_server, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                   &opt, sizeof(opt)))
     {
         perror("setsockopt");
         exit(EXIT_FAILURE);
     }
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
      cout << "TEST BC "<<endl;

      int a2 = connecte(AIRPORT1);
      cout << "4  : "<<a2 <<";"<< endl;
      if(a2 > 0) {
        struct args_nd arguments1;
        arguments1.sock = a2;
        arguments1.choix = 1;
        pthread_t tid;
        cout<<"BC : AVANT THREAD"<<endl;
        pthread_create(&tid,NULL,runClient,(void*)&arguments1);
      } else {
        cout<<"BC : FAIL"<<endl;
      }
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
      cout<<"END CONNECT 4 "<<endl;
      sleep(1);

    while(1){
      int new_sock;
      if ((new_sock = accept(Sock_server, (struct sockaddr *)&address,
                        (socklen_t*)&addrlen))<0)
     {
         perror("accept");
         exit(EXIT_FAILURE);
     }
      bc->getSocket().push_back(new_sock);
      pthread_t threadid;
      bc->getIdThread().push_back(threadid);
      pthread_create(&bc->getIdThread().at(bc->getSocket().size()-1),NULL,runClient,(void*)&new_sock);
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

void * runClient(void* args){
  cout<<"RUN CLIENT : entrée"<<endl;
  int nb;
  char buffer[1024] = {0};
  cout<<"RUN CLIENT : avant struct"<<endl;
  cout<<"RUN CLIENT : struct  : "<<*(int*)args<<endl;
  cout<<"runClient : apres struct  "<<endl;
  while(1){
    cout <<"run Client : avant read"<<endl;
    nb = read( *(int*)args , buffer, 1024);
    cout<<"RUN CLIENT : apres reead"<<endl;
    if(nb == 0){
      printf("buffer containt nothing\n");
    } else {
      printf("message : %s\n",buffer);
    }
    cout<<"RUN CLIENT : fin"<<endl;
  }
}
