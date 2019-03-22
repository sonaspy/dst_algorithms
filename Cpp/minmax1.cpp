// find the index/location of the min and max elements of a sequence

#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
bool minmax(T a[], int n, int& indexOfMin, int& indexOfMax)
{// Locate min and max elements in a[0:n-1].
 // Return false if less than one element.
   if (n < 1) return false;
   indexOfMin = indexOfMax = 0; // initial guess
   for (int i = 1; i < n; i++)
   {
      if (a[indexOfMin] > a[i]) indexOfMin = i;
      if (a[indexOfMax] < a[i]) indexOfMax = i;
   }
   return true;
}

int main()
{
   int a[6] = {2, 6, 4, 3, 1, 5};
   int n = 6, theMin, theMax;

   // output the array elements
   std::cout << "a[0:5] = ";
   copy(a, a+6, ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;

   // locate min and max
   minmax(a,n,theMin,theMax);

   // output locations and values
   std::cout << "The min element is at " << theMin  << std::endl
        << "Its value is " << a[theMin] << std::endl;
   std::cout << "The max element is at " << theMax  << std::endl
        << "Its value is " << a[theMax] << std::endl;
   return 0;
}
