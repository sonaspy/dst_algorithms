// test the class circularListWithHeader
#include<iostream>
#include "circularListWithHeader.h"

using namespace std;

int main()
{
   // test constructor
   circularListWithHeader<int> y, z;

   // test size
   std::cout << "Initial size of y and z = "
        << y.size() << ", "
        << z.size() << std::endl;

   // test insert
   y.insert(0, 2);
   y.insert(1, 6);
   y.insert(0, 1);
   y.insert(2, 4);
   y.insert(3, 5);
   y.insert(2, 3);
   std::cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << std::endl;
   std::cout << "Size of y = " << y.size() << std::endl;
   y.output(std::cout);
   std::cout << std::endl << "Testing overloaded <<" << std::endl;
   std::cout << y << std::endl;

   // test indexOf
   int index = y.indexOf(4);
   if (index < 0) std::cout << "4 not found" << std::endl;
   else std::cout << "The index of 4 is " << index << std::endl;

   index = y.indexOf(7);
   if (index < 0) std::cout << "7 not found" << std::endl;
   else std::cout << "The index of 7 is " << index << std::endl;

   return 0;
}
