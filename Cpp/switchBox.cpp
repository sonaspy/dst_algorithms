// switch box routing

#include <iostream>
#include "arrayStack.h"

using namespace std;

bool checkBox(int net[], int n)
{// Determine whether the switch box is routable.
 // net[0..n-1] is array of pin to net assignments.
 // n is number of pins.

   arrayStack<int>* s = new arrayStack<int>(n);

   // scan nets clockwise
   for (int i = 0; i < n; i++)
      // process pin i
      if (!s->empty())
         // check with top net
         if (net[i] == net[s->top()])
            // net[i] is routable, delete from stack
            s->pop();
         else s->push(i);
      else s->push(i);

   // any unrouted nets left?
   if (s->empty())
   {// no nets remain
       std::cout << "Switch box is routable" << std::endl;
       return true;
    }

   std::cout << "Switch box is not routable" << std::endl;
   return false;
}

void main()
{
   // input the number of pins and their net assignment
   std::cout << "Type number of pins in switch box" << std::endl;
   int n;
   std::cin >> n;

   // create net assignment array
   int* net = new int[n];

   // input the net assignments
   std::cout << "Type net numbers for pins 1 through "  << n << std::endl;
   for (int i = 0; i < n; i++)
      std::cin >> net[i];

   // see if the switch box is routable
   checkBox(net, n);
}
