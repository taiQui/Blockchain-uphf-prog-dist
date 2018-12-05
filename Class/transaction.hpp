#ifndef transaction_hpp
#define transaction_hpp

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>


using namespace std; //If there is a problem during the compilation, try without the namespace

class Transaction { //Abstract class
  //A transaction has this form: [type_of_transaction][id_1, id_2][Luggage and id_client][flight_number]

  //Attributes
private:
   int _type; //Type of transaction (1,2 or 3)
   string _id_exchange[2]; //Couple of id of each part of the transaction
   vector<string> _luggage; // List of luggages, with their name, weigh and the id of the client
   string _flight_number; //flight number

  //Methods
public:
   Transaction(); //Constructor
   ~Transaction(); //Destructor
   void settype(int); //Setter for type
   int gettype(); //Getter for type

   void setid_exchange(string, string); //Setter for id_exchange
   string* getid_exchange(); //Getter for id_exchange

   void setluggage(string,string); //Setter for luggage
   string* getluggage(int); //Getter for luggage

   void setflight_number(string); //Setter for flight_number
   string getflight_number(); //Getter for flight_number

   bool verification();

};

#endif
