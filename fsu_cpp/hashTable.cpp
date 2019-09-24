// test hash table class
#include <iostream>
#include "hashTable.h"

using namespace std;

void main()
{
   hashTable<int, int> z(11);
   pair<int, int> p;

   // test insert
   p.first = 2; p.second = 10;
   z.insert(p);
   p.first = 10; p.second = 50;
   z.insert(p);
   p.first = 24; p.second = 120;
   z.insert(p);
   p.first = 32; p.second = 160;
   z.insert(p);
   p.first = 3; p.second = 15;
   z.insert(p);
   p.first = 12; p.second = 60;
   z.insert(p);
   std::cout << "The dictionary is " << std::endl << z << std::endl;
   std::cout << "Its size is " << z.size() << std::endl;

   // test find
   std::cout << "Element associated with 2 is " << z.find(2)->second << std::endl;
   std::cout << "Element associated with 10 is " << z.find(10)->second << std::endl;
   std::cout << "Element associated with 12 is " << z.find(12)->second << std::endl;

}
