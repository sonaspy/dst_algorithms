// test the class vectorList that uses a vector for the list elements
#include<iostream>
#include<numeric>
#include<algorithm>   // has reverse
#include<functional>  // has greater
#include "linearList.h"
#include "vectorList.h"

using namespace std;

int main()
{
   // test constructor
   linearList<double> *x = new vectorList<double>(20);
   vectorList<int> y(2), z;

   // test capacity
   std::cout << "Capacity of x, y and z = "
        << ((vectorList<double>*) x)->capacity() << ", "
        << y.capacity() << ", "
        << z.capacity() << std::endl;


   // test size
   std::cout << "Initial size of x, y, and z = "
        << x->size() << ", "
        << y.size() << ", "
        << z.size() << std::endl;

   // test empty
   if (x->empty()) std::cout << "x is empty" << std::endl;
   else std::cout << "x is not empty" << std::endl;
   if (y.empty()) std::cout << "y is empty" << std::endl;
   else std::cout << "y is not empty" << std::endl;

   // test insert
   y.insert(0, 2);
   y.insert(1, 6);
   y.insert(0, 1);
   y.insert(2, 4);
   y.insert(3, 5);
   y.insert(2, 3);
   std::cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << std::endl;
   std::cout << "Size of y = " << y.size() << std::endl;
   std::cout << "Capacity of y = " << y.capacity() << std::endl;
   if (y.empty()) std::cout << "y is empty" << std::endl;
   else std::cout << "y is not empty" << std::endl;
   y.output(std::cout);
   std::cout << std::endl << "Testing overloaded <<" << std::endl;
   std::cout << y << std::endl;

   // test indexOf
   int index = y.indexOf(4);
   if (index < 0) std::cout << "4 not found" << std::endl;
   else std::cout << "The index of 4 is " << index << std::endl;

   index = y.indexOf(7);
   if (index < 0) std::cout << "7 not found" << std::endl;
   else std::cout << "The index of 7 is " << index << std::endl;

   // test get
   std::cout << "Element with index 0 is " << y.get(0) << std::endl;
   std::cout << "Element with index 3 is " << y.get(3) << std::endl;

   // test erase
   y.erase(1);
   std::cout << "Element 1 erased" << std::endl;
   std::cout << "The list is "  << y << std::endl;
   y.erase(2);
   std::cout << "Element 2 erased" << std::endl;
   std::cout << "The list is "  << y << std::endl;

   std::cout << "Size of y = " << y.size() << std::endl;
   std::cout << "Capacity of y = " << y.capacity() << std::endl;
   if (y.empty()) std::cout << "y is empty" << std::endl;
   else std::cout << "y is not empty" << std::endl;

   try {y.insert(-3, 0);}
   catch (illegalIndex e)
   {
      std::cout << "Illegal index exception" << std::endl;
      std::cout << "Insert index must be between 0 and list size" << std::endl;
      e.outputMessage();
   }

   // test copy constructor
   vectorList<int> w(y);
   y.erase(0);
   y.erase(0);
   std::cout << "w should be old y, new y has first 2 elements removed" << std::endl;
   std::cout << "w is " << w << std::endl;
   std::cout << "y is " << y << std::endl;
   
   // a few more inserts, just for fun
   y.insert(0,4);
   y.insert(0,5);
   y.insert(0,6);
   y.insert(0,7);
   std::cout << "y is " << y << std::endl;

   // test iterator
   std::cout << "Ouput using forward iterators pre and post ++" << std::endl;
   for (vectorList<int>::iterator i = y.begin();
        i != y.end(); i++)
      std::cout << *i << "  ";
   std::cout << std::endl;
   for (vectorList<int>::iterator i = y.begin();
        i != y.end(); ++i)
      std::cout << *i << "  ";
   std::cout << std::endl;

   std::cout << "Ouput using backward iterators pre and post --" << std::endl;
   for (vectorList<int>::iterator i = y.end();
        i != y.begin(); std::cout << *(--i) << "  ");
   std::cout << std::endl;
   for (vectorList<int>::iterator i = y.end();
        i != y.begin();)
      {i--; std::cout << *i << "  "; *i += 1;} 
   std::cout << std::endl;
   std::cout << "Incremented by 1 list is " << y << std::endl;
   
   // try out some STL algorithms
   reverse(y.begin(), y.end());
   std::cout << "The reversed list is " << y << std::endl;
   int sum = accumulate(y.begin(), y.end(), 0);
   std::cout << "The sum of the elements is " << sum << std::endl;
   sort(y.begin(), y.end());
   std::cout << "The sorted list is " << y << std::endl;
   sort(y.begin(), y.end(), greater<int>());
   std::cout << "The list is descending order is " << y << std::endl;
   return 0;
}

