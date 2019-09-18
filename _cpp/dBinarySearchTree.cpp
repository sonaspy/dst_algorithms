// test binary search tree with duplicates class

#include <iostream>
#include "dBinarySearchTree.h"

using namespace std;


int main(void)
{
   dBinarySearchTree<int, char> y;
   y.insert(pair<int, char>(1, 'a'));
   y.insert(pair<int, char>(6, 'f'));
   y.insert(pair<int, char>(3, 'c'));
   y.insert(pair<int, char>(4, 'e'));
   y.insert(pair<int, char>(1, 'b'));
   y.insert(pair<int, char>(6, 'g'));
   y.insert(pair<int, char>(3, 'd'));
   std::cout << "Tree size is " << y.size() << std::endl;
   std::cout << "Elements in ascending order are" << std::endl;
   y.ascend();

   pair<const int, char> *s = y.find(3);
   std::cout << "Search for 3 succeeds " << std::endl;
   std::cout << s->first << ' ' << s->second << std::endl;
   y.erase(3);
   std::cout << "3 deleted " << std::endl;
   std::cout << "Tree size is " << y.size() << std::endl;
   std::cout << "Elements in ascending order are" << std::endl;
   y.ascend();

   s = y.find(3);
   std::cout << "Search for 3 succeeds " << std::endl;
   std::cout << s->first << ' ' << s->second << std::endl;
   y.erase(3);
   std::cout << "3 deleted " << std::endl;
   std::cout << "Tree size is " << y.size() << std::endl;
   std::cout << "Elements in ascending order are" << std::endl;
   y.ascend();

   s = y.find(1);
   std::cout << "Search for 1 succeeds " << std::endl;
   std::cout << s->first << ' ' << s->second << std::endl;
   y.erase(1);
   std::cout << "1 deleted " << std::endl;
   std::cout << "Tree size is " << y.size() << std::endl;
   std::cout << "Elements in ascending order are" << std::endl;
   y.ascend();

   s = y.find(8);
   if (s == NULL)
      std::cout << "Search for 8 fails " << std::endl;
   std::cout << "Tree size is " << y.size() << std::endl;
   std::cout << "Elements in ascending order are" << std::endl;
   y.ascend();

   s = y.find(6);
   std::cout << "Search for 6 succeeds " << std::endl;
   std::cout << s->first << ' ' << s->second << std::endl;
   y.erase(6);
   std::cout << "6 deleted " << std::endl;
   std::cout << "Tree size is " << y.size() << std::endl;
   std::cout << "Elements in ascending order are" << std::endl;
   y.ascend();

   y.insert(pair<int, char>(1, 'a'));
   y.insert(pair<int, char>(6, 'f'));
   y.insert(pair<int, char>(3, 'c'));
   y.insert(pair<int, char>(4, 'e'));
   y.insert(pair<int, char>(1, 'b'));
   y.insert(pair<int, char>(6, 'g'));
   y.insert(pair<int, char>(3, 'd'));
   std::cout << "Tree size is " << y.size() << std::endl;
   std::cout << "Elements in ascending order are" << std::endl;
   y.ascend();
}
