
// sum n numbers using the STL algorithm accumulate
#include <iostream>
// #include <algorithm>
#include <numeric>    // has accumulate

using namespace std;

template<class T>
T sum(T a[], int n)
{// Return sum of the numbers a[0:n-1].
   T theSum = 0;
   return accumulate(a, a+n, theSum);
}

int main()
{
   int a[6] = {1, 2, 3, 4, 5, 6};

   // output the array elements
   std::cout << "a[0:5] = ";
   copy(a, a+6, ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;

   // test the function sum
   std::cout << "sum(a,0) = " << sum(a,0) << std::endl;
   std::cout << "sum(a,1) = " << sum(a,1) << std::endl;
   std::cout << "sum(a,6) = " << sum(a,6) << std::endl;
   return 0;
}
