// test quick sort

#include <iostream>
#include <algorithm> // has copy
#include "quickSort.h"

using namespace std;


int main()
{
   int a[10] = {10,7,8,9,4, 2, 3, 6, 5,1};

   // output the elements
   std::cout << "a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;

   // sort
   quickSort(a,10);

   // output the sorted sequence
   std::cout << "After the sort, a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;
   return 0;
}
