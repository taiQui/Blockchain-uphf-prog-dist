#ifndef headers_hpp
#define headers_hpp



#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include  <sys/ioctl.h>
#include <signal.h>
#include <ifaddrs.h>
#include "main.hpp"


#define AIRPORT1 5000
#define AIRPORT2 5001
#define AIRPORT3 5002
#define BLOCKCHAIN 5003

void * runNode1(void*);
void * runNode2(void*);
void * runNode3(void*);
void * runBlockchain(void*);
void * runClient(void*);
void * runListen(void*);

int connecte(int);


#endif
