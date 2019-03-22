// match parentheses

#include <iostream>
#include <string>
#include "arrayStack.h"

using namespace std;


void printMatchedPairs(string expr)
{// Parenthesis matching.
   arrayStack<int> s;
   int length = (int) expr.size();

   // scan expression expr for ( and )
   for (int i = 0; i < length; i++)
      if (expr.at(i) == '(') 
         s.push(i);
      else
         if (expr.at(i) == ')')
   	 try
         {// remove location of matching '(' from stack
            std::cout << s.top() << ' ' << i << std::endl;
            s.pop();  // unstack match
         }
         catch (stackEmpty)
         {// stack was empty, no match exists
            std::cout << "No match for right parenthesis"
                 << " at " << i << std::endl;
         }

   // remaining '(' in stack are unmatched
   while (!s.empty()) 
   {
      std::cout << "No match for left parenthesis at "
           << s.top() << std::endl;
      s.pop();
   }
}

int main(void)
{
   string expr;
   std::cout << "Type an expression" << std::endl;
   std::cin >> expr;
   std::cout <<"The pairs of matching parentheses in"
        << std::endl << expr << std::endl << "are" << std::endl;

   printMatchedPairs(expr);

   return 0;
}
