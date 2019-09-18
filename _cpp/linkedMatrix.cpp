// test linked sparse matrix class

#include <iostream>
#include "linkedMatrix.h"

using namespace std;

int main(void)
{
   linkedMatrix<int> a, b, c;

   // test input and output
   std::cin >> a;
   std::cout << "Matrix a is" << std::endl << a;
   std::cin >> b;
   std::cout << "Matrix b is" << std::endl << b;

   // test transpose
   a.transpose(c);
   std::cout << "The transpose of a is" << std::endl << c;

   return 0;
}
