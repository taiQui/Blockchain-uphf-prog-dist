#ifndef block_hpp
#define block_hpp

#include <iostream>
#include <string>

using namespace std;

#include "transaction.hpp"

class Block {
  private:
    string _hash;
    //pointer on previous block
    Block* _inferiorBlock;
    // add timer
    int _length;
    vector<Transaction> _transactionList;

  public:
    //Constructor
    Block();
    Block(string,Block*,int,vector<Transaction>);
    // Block(Block);
    //Destrucor
    ~Block();

    //GETTER
    string getHash();
    Block* getInferiorBlock();
    int getLength();
    vector<Transaction> getTransactionByType(int);
    Transaction getTransactionByIndex(unsigned int);
    vector<Transaction> getAllList();
    void setAllList(vector<Transaction>);
    //SETTER
    void setHash(string);
    void setInferiorBlock(Block*  );
    void setLength(int);
    //Adding transaction to block
    void addTransaction(Transaction);
    //Delete Transaction to a block
    void removeTransaction(Transaction);
    //control length
    bool checkIndex(unsigned int);

};

#endif
