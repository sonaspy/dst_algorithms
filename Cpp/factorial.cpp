
// compute n!

#include <iostream>

using namespace std;

int factorial(int n)
{// Compute n!
   if (n <= 1) return 1;
   else return n * factorial(n - 1);
}

int main()
{// test the function
   std::cout << "0! = " << factorial(0) << std::endl;
   std::cout << "1! = " << factorial(1) << std::endl;
   std::cout << "5! = " << factorial(5) << std::endl;
   return 0;
}
