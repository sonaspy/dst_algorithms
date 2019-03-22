// test currency class with friend

#include <iostream>
#include "currencyFriend.h"

using namespace std;

int main()
{
   currency g, h(plus, 3, 50), i, j;

   // try out both forms of setValue
   g.setValue(minus, 2, 25);
   i.setValue(-6.45);

   // do an add and output
   j = h + g;
   std::cout << h << " + " << g << " = " << j << std::endl;

   // do an increment and output
   std::cout << i << " incremented by " << h
        << " is " << (i += h) << std::endl;

   // do two adds in a sequence
   j = i + g + h;
   std::cout << i << " + " << g << " + " 
        << h << " = " << j << std::endl;

   // do an increment and add
   std::cout << "Increment " << i << " by " << g
        << " and then add " << h << std::endl;
   j = (i += g) + h;
   std::cout << "Result is " << j << std::endl;
   std::cout << "Incremented object is " << i << std::endl;

   // test the exception
   std::cout << "Attempting to initialize with cents = 152" << std::endl;
   try {i.setValue(plus, 3, 152);}
   catch (illegalParameterValue e) {
      std::cout << "Caught thrown exception" << std::endl;
      e.outputMessage();
       }
   return 0;
}
