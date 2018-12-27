#include "transaction.hpp"


//Constructor
Transaction::Transaction(int type, string id_exchange[2], vector<string> luggage, string flight_number){
this->_type = type;
for(int i(0); i<2; i++) this->_id_exchange[i] = id_exchange[i];
this->_luggage = luggage;
this->_flight_number = flight_number;
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
  this->_id_exchange[0] = airportSender;
  this->_id_exchange[1] = airportReceiver;
}
//GETTER
string Transaction::getid_exchangeSender(){
  return this->_id_exchange[0];
}
string Transaction::getid_exchangeReceiver(){
  return this->_id_exchange[1];
}
//SETTER
void Transaction::setluggage(string name,string weight,string id){
  this->_luggage.push_back(name);
  this->_luggage.push_back(weight);
  this->_luggage.push_back(id);
}

//Create String's pointer to return all bagage information
string* Transaction::getluggage(int index){
  string* bagage = new string[3];
  bagage[0] = this->_luggage[index];
  bagage[1] = this->_luggage[index+1];
  bagage[2] = this->_luggage[index+2];
  return bagage;
}
//SETTER
void Transaction::setflight_number(string number){
  this->_flight_number = number;
}

//GETTER
string Transaction::getflight_number(){
  return this->_flight_number;
}

void Transaction::getAllLuggage(){
  for(unsigned int i = 0; i < this->_luggage.size(); i+=3){
    cout << " Luggage "<<endl<<"---------"<<endl<<"name  : " << this->_luggage.at(i) << endl <<"weight : "<<this->_luggage.at(i+1)<<endl<<"client ID : "<<this->_luggage.at(i+2)<<endl<<"---------"<<endl;
  }
}
//verification function
//verify if _id_exchange is good for type entered
bool Transaction::verification(){
  switch(this->_type){
    case 1:
      return(this->_id_exchange[0][0] == 'C' && this->_id_exchange[1][0] == 'A' );
      break;
    case 2:
      return(this->_id_exchange[0][0] == 'A' && this->_id_exchange[1][0] == 'C' );
      break;
    case 3:
      return(this->_id_exchange[0][0] == 'A' && this->_id_exchange[1][0] == 'A' );
      break;
    default:
      cout << "You have entered bad type of transaction" << endl;
      return false;
      break;
  }
}

// unsigned int because vector iterator need either unsigned int or to create directly iterator <--- very anoying
void Transaction::removeLuggageWithName(string name){
  unsigned int i = 0;
  bool continuer = true;
  while (continuer && i < this->_luggage.size()){
    // vector.at()   <--- need unsigned int and work same as operator[]
    if(this->_luggage.at(i) == name){
      // vector.erase need iterator : vector.begin() : iterator begin and vector.end() : end iterator
      this->_luggage.erase(this->_luggage.begin()+(i+2));
      this->_luggage.erase(this->_luggage.begin()+(i+1));
      this->_luggage.erase(this->_luggage.begin()+i);
      continuer = false;
    } else {
      i+=3;
    }
  }
}


//revmoce luggage with client ID
void Transaction::removeLuggageWithId(string id){
  unsigned int i = 0;
  bool continuer = true;
  while (continuer && i < this->_luggage.size()){
    if(this->_luggage.at(i+2) == id){
      this->_luggage.erase(this->_luggage.begin()+(i+2));
      this->_luggage.erase(this->_luggage.begin()+(i+1));
      this->_luggage.erase(this->_luggage.begin()+i);
      continuer = false;
    } else {
      i+=3;
    }
  }
}
