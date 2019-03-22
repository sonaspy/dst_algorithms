// test diagonal matrix class

#include <iostream>
#include "diagonalMatrix.h"

using namespace std;

int main(void)
{
   diagonalMatrix<int> x(20);
   x.set(1,1,22);
   x.set(5,5,44);
   x.set(8,5,0);
   std::cout << x.get(5,5) << std::endl;
   std::cout << x.get(1,1) << std::endl;
   std::cout << x.get(10,1) << std::endl;
   
   return 0;
}
