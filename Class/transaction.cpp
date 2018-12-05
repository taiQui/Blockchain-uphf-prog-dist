#include "transaction.hpp"


//Constructor
Transaction::Transaction(){

}
//Destructor
Transaction::~Transaction(){

}
//SETTER
void Transaction::settype(int type){
  this->_type = type;
}
//GETTER
int Transaction::gettype(){
  return this->_type;
}
//SETTER
void Transaction::setid_exchange(string airportSender,string airportReceiver){
  this._id_exchange[0] = airportSender;
  this._id_exchange[1] = airportReceiver;
}
//GETTER
string* Transaction::getid_exchange(){
  return this._id_exchange;
}
//SETTER
void Transaction::setluggage(string bagage,string weight){
  this._luggage.push_back(bagage);
  this._luggage.push_back(weight);
}
string* Transaction::getluggage(){

}
//SETTER
void Transaction::setflight_number(string number){
  this._flight_number = number;
}

//GETTER
string Transaction::getflight_number(){
  return this._flight_number;
}
//verification function
//verify if _id_exchange is good for type entered
bool Transaction::verification(){
  switch(this._type){
    case 1:
      return(this._id_exchange[0][0] == 'C' && this._id_exchange[1][0] == 'A' );
      break;
    case 2:
      return(this._id_exchange[0][0] == 'A' && this._id_exchange[1][0] == 'C' );
      break;
    case 3:
      return(this._id_exchange[0][0] == 'A' && this._id_exchange[1][0] == 'A' );
      break;
    default:
      cout << "You have entered bad type of transaction" << endl;
      return false;
      break;
  }
}
