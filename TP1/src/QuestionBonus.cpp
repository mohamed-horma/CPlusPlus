/*
 * @file   QuestionBonus.cpp
 * @brief  Surcharge et portées.
 */
#include <iostream>
#include <iomanip>
using namespace std;

void display( double price ) {
  cout << price << endl;
}

void applyVAT( double * price )
{
  (*price) *= 1.196;
}

namespace MyLib {
  void applyVAT( double & price )
  {
    price *= 1.196;
  }
  void foo( double * price );
}

int main()
{
  double price = 2.5;
  applyVAT( &price );
  MyLib::applyVAT( price );
  display( price );
  MyLib::foo( &price );
}

namespace MyLib {
  void foo( double * price ) {
    display( *price );
    applyVAT( *price );
  }
}
