// using an array iterator
#include <iostream>

using namespace std;

int main()
{
   int x[3] = {0, 1, 2};

   // use a pointer y to iterate through the array x
   for (int* y = x; y != x + 3; y++)
      std::cout << *y << "  ";
   std::cout << std::endl;
   return 0;
}
