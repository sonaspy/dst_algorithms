// test sorted chain class
#include<iostream>
#include "sortedChain.h"

using namespace std;

void main()
{
   sortedChain<int, int> z;
   pair<int, int> p;

   // test insert
   p.first = 2; p.second = 10;
   z.insert(p);
   p.first = 10; p.second = 50;
   z.insert(p);
   p.first = 6; p.second = 30;
   z.insert(p);
   p.first = 8; p.second = 40;
   z.insert(p);
   p.first = 1; p.second = 5;
   z.insert(p);
   p.first = 12; p.second = 60;
   z.insert(p);
   std::cout << "The chain is " << z << std::endl;
   std::cout << "Its size is " << z.size() << std::endl;

   // test find
   std::cout << "Element associated with 1 is " << z.find(1)->second << std::endl;
   std::cout << "Element associated with 6 is " << z.find(6)->second << std::endl;
   std::cout << "Element associated with 12 is " << z.find(12)->second << std::endl;

   // test erase
   z.erase(1);
   z.erase(2);
   z.erase(6);
   z.erase(12);
   std::cout << "Deleted 1, 2, 6, 12" << std::endl;
   std::cout << "The chain is " << z << std::endl;
   std::cout << "Its size is " << z.size() << std::endl;
}
