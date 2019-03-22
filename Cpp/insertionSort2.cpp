// test insertion sort

#include <iostream>
#include <algorithm> // has copy
#include "insertionSort.h"

using namespace std;


int main()
{
   int a[10] = {3, 2, 4, 1, 6, 9, 8, 7, 5, 0};

   // output the elements
   std::cout << "a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;

   // sort
   insertionSort(a,10);

   // output the sorted sequence
   std::cout << "After the sort, a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;
   return 0;
}
