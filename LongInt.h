//Authort: Darryl Beckham and Kevin Ip
//
//
//
#ifndef LONGINT_H
#define LONGINT_H

#include <stack>
#include <fstream>
//#include "LinkedList.h"
//#include "StackLi.h"


using namespace std;

class LongInt;

class LongInt
{

  public:
    int num_digits;
    LongInt& operator+(LongInt& rhs);
    LongInt& operator=(LongInt& rhs);
    bool operator!=(LongInt rhs);
    stack<int> result;
    friend istream& operator>>(istream& is, LongInt& rhs);
    friend ostream& operator<<(ostream& os, LongInt rhs);


  protected:


  private:


};

#endif
