// test array based sparse matrix class

#include <iostream>
#include "sparseMatrix.h"

int main(void)
{
   sparseMatrix<int> a, b, c;

   // test input and output
   std::cin >> a;
   std::cout << "Matrix a is" << std::endl << a;
   std::cin >> b;
   std::cout << "Matrix b is" << std::endl << b;

   // test transpose
   a.transpose(c);
   std::cout << "The transpose of a is" << std::endl << c;

   // test add
   a.add(b,c);
   std::cout << "The sum of a and b is" << std::endl << c;

   return 0;
}
