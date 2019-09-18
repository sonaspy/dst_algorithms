// simple histogramming program

#include <iostream>

using namespace std;

void main(void)
{// Histogram of nonnegative integer values.
   int n,  // number of elements
       r;  // values between 0 and r
   std::cout << "Enter number of elements and range"
        << std::endl;
   std::cin >> n >> r;

   // create histogram array h
   int *h = new int[r+1];

   // initialize array h to zero
   for (int i = 0; i <= r; i++)
      h[i] = 0;

   // input data and compute histogram
   for (i = 1; i <= n; i++)
   {// assume input values are between 0 and r
      int key;  // input value
      std::cout << "Enter element " << i << std::endl;
      std::cin >> key;
      h[key]++;
   }

   // output histogram
   std::cout << "Distinct elements and frequencies are"
        << std::endl;
   for (i = 0; i <= r; i++)
      if (h[i] != 0)
         std::cout << i << "   "  << h[i] << std::endl;
}
