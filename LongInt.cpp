//Author: Darryl Beckham and Kevin Ip

#include <iostream>
#include "LongInt.h"

using namespace std;

static stack<int> num1, num2, result;
int flag = 0;

LongInt& LongInt::operator+(LongInt& rhs)
{
    int carry = 0;
    //printf("%d\n%d\n", this->num_digits, rhs.num_digits);
    if(this->num_digits <= rhs.num_digits)
    {
      while(!num1.empty())
      {
        int sum = num1.top() + num2.top() + carry;
        num1.pop();
        num2.pop();
        if(sum > 9)
        {
          carry = 1;
          sum = sum - 10;
        }
        else
        {
          carry = 0;
        }
        result.push(sum);
      }
      while(!num2.empty())
      {
        int sum = num2.top() + carry;
        num2.pop();
        if(sum > 9)
        {
          carry = 1; sum = sum - 10;
        }
        else carry = 0;
        result.push(sum);
      }

      if(num1.empty() && num2.empty() && carry == 1)
      {
        result.push(1);
      }
    }

    if(this->num_digits > rhs.num_digits)
    {
      while(!num2.empty())
      {
        int sum = num1.top() + num2.top() + carry;
        num1.pop();
        num2.pop();
        if(sum > 9)
        {
          carry = 1;
          sum = sum - 10;
        }
        else
        {
          carry = 0;
        }
        result.push(sum);
      } 
      while(!num1.empty())
      {
        int sum = num1.top() + carry;
        num1.pop();
        if(sum > 9)
        {
          carry = 1; sum = sum - 10;
        }
        else carry = 0;
        result.push(sum);
      }
      if(num1.empty() && num2.empty() && carry == 1)
      {
        result.push(1);
      }
    }
  LongInt* lhs = new LongInt;
  lhs->result = result;
  return *lhs;
}

bool LongInt::operator!=(LongInt rhs)
{
//pseudocode, won't compile
//
/* 
 if(this.num_digits != rhs.num_digits)
  {
    return true;
  }
  else
  {
    for(int i = 0; i <= smaller_num.size(); i++)
    {
      if(larger_num[i] != smaller_num[i])
      {
        return true;
      }
      else
      {
        continue;
      }
    }
  }
  return false;
*/
}

LongInt& LongInt::operator=(LongInt& rhs)
{
  this->result = rhs.result;
  return *this;
}

istream& operator>>(istream& is, LongInt& rhs)
{
  //num_itr = result.List<int>::zeroth(); 
  rhs.num_digits = 0;
  while(isdigit(is.peek()))
  {
    int tmp = getchar() - 48;
    if(!flag)
    {
      rhs.num_digits++;
      num1.push(tmp);
    }
    if(flag)
    {
      rhs.num_digits++;
      num2.push(tmp);
    }
    //printf("%d\n", rhs.num_digits);
  }
  getchar();
  flag++;
}

ostream& operator<<(ostream& os, LongInt rhs)
{
  while(!(rhs.result.empty()))
  {
    os << rhs.result.top();
    rhs.result.pop();
  }
  return os;
}
