// test select

#include <iostream>
#include <algorithm> // has copy
#include "select.h"

using namespace std;

int main()
{
   int a[10] = {10,7,8,9,4, 2, 3, 6, 5,1};
   int n = 10;

   // output the elements
   std::cout << "a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;

   // select and output
   for (int i = 1; i <= n; i++)
      std::cout << "The " << i << "'th element is " << select(a, n, i) << std::endl;
   return 0;
}
