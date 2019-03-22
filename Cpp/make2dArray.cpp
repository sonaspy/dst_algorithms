// test the function make2dArray

#include <iostream>
#include "make2dArray.h"

using namespace std;

int main()
{
   int **a;
   // make a 2 x 2 array
   make2dArray(a,2,2);

   // assign values to all elements of the array
   a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;

   // output assigned values
   std::cout << a[0][0] << ' ' << a[0][1] << std::endl;
   std::cout << a[0][0] << ' ' << a[1][1] << std::endl;
   return 0;
}
