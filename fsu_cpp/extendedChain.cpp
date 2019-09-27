// test extended chain
#include<iostream>
#include<numeric>     // has accumulate
#include "extendedChain.h"

using namespace std;

int main()
{
   // create an extended chain
   extendedChain<int> y;
   y.insert(0, 2);
   y.insert(1, 6);
   y.insert(0, 1);
   y.insert(2, 4);
   y.insert(3, 5);
   y.insert(2, 3);
   std::cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << std::endl;
   std::cout << "Size of y = " << y.size() << std::endl;

   // test iterator
   std::cout << "Ouput using forward iterators pre and post ++" << std::endl;
   for (extendedChain<int>::iterator i = y.begin();
        i != y.end(); i++)
      std::cout << *i << "  ";
   std::cout << std::endl;
   for (extendedChain<int>::iterator i = y.begin();
        i != y.end(); ++i)
   {
      std::cout << *i << "  ";
      *i += 1;
   }
   std::cout << std::endl;

   std::cout << "Incremented by 1 list is " << y << std::endl;
   
   // try out an STL algorithm
   int sum = accumulate(y.begin(), y.end(), 0);
   std::cout << "The sum of the elements is " << sum << std::endl;

   // clear the chain and do a few appends
   y.clear();
   y.push_back(1);
   y.push_back(2);
   y.push_back(3);
   std::cout << "Appended 3 integers, list y should be 1 2 3" << std::endl;
   std::cout << "Size of y = " << y.size() << std::endl;
   std::cout << y << std::endl;

   y.insert(3,4);
   y.insert(0,0);
   std::cout << "List y should be 0 1 2 3 4" << std::endl;
   std::cout << "Size of y = " << y.size() << std::endl;
   std::cout << y << std::endl;

   y.erase(4);
   y.erase(0);
   y.push_back(6);
   std::cout << "List y should be 1 2 3 6" << std::endl;
   std::cout << "Size of y = " << y.size() << std::endl;
   std::cout << y << std::endl;

   return 0;
}