// test matrix transpose

#include <iostream>
#include "matrixWithTranspose.h"

using namespace std;
int main(void)
{
   matrix<int> x(3,2), y, z;
   for (int i = 1; i <= 3; i++)
      for (int j = 1; j <= 2; j++)
         x(i,j) = 2*i + j;
   std::cout << "Initialized x(i,j) = 2*i + j" << std::endl;
   std::cout << "x is" << std::endl;;
   std::cout << x << std::endl;

    x.transpose(y);
   std::cout << "Assigned y = x.transpose" << std::endl;
   std::cout << "y is" << std::endl;
   std::cout << y << std::endl;

   return 0;
}
