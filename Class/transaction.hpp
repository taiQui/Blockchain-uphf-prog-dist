#ifndef transaction_hpp
#define transaction_hpp

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#endif

using namespace std; //If there is a problem during the compilation, try without the namespace

class Transaction{ //Abstract class
  //A transaction has this form: [type_of_transaction][id_1, id_2][Luggage and id_client][flight_number]

  //Attributes
  private int type; //Type of transaction (1,2 or 3)
  private string id_exchange[2]; //Couple of id of each part of the transaction
  private vector<string> luggage; // List of luggages, with their name, weigh and the id of the client
  private string flight_number; //flight number

  //Methods
  virtual Transaction(); //Constructor
  virtual ~Transaction(); //Destructor

  public void settype(int); //Setter for type
  public int gettype(); //Getter for type

  public void setid_exchange(string, string); //Setter for id_exchange
  public string[] getid_exchange(); //Getter for id_exchange

  public void setluggage(string,string); //Setter for luggage
  public string[] getluggage(int); //Getter for luggage

  public void setflight_number(string); //Setter for flight_number
  public string getflight_number(); //Getter for flight_number


};
