// find location of maximum of n numbers

#include <iostream>
#include <algorithm> // has copy
#include "indexOfMax.h"

using namespace std;

int main()
{
   int a[6] = {1, 4, 2, 5, 6, 3};

   // output the array elements
   std::cout << "a[0:5] = ";
   copy(a, a+6, ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;

   // test the function indexOfMax
   std::cout << "max(a,1) = " << a[indexOfMax(a,1)] << std::endl;
   std::cout << "max(a,3) = " << a[indexOfMax(a,3)] << std::endl;
   std::cout << "max(a,6) = " << a[indexOfMax(a,6)] << std::endl;
   return 0;
}
