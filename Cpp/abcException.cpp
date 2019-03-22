// function to compute an expression using int value parameters
// throw an exception of type illegalParameterValue
// in case one of the parameters is <= 0

#include<iostream>
#include "myExceptions.h"

using namespace std;

int abc(int a, int b, int c)
{
   if (a <= 0 || b <= 0 || c <= 0)
       throw illegalParameterValue ("All parameters should be > 0");
   return a + b * c;
}

int main()
{
   try {std::cout << abc(2,0,4) << std::endl;}
   catch (illegalParameterValue e)
   {
      std::cout << "The parameters to abc were 2, 0, and 4" << std::endl;
      std::cout << "illegalParameterValue exception thrown" << std::endl;
      e.outputMessage();
      return 1;
   }
   return 0;
}

