// test array stack

#include <iostream>
#include "arrayStack.h"
#include "myExceptions.h"

using namespace std;

int main(void)
{
   arrayStack<int> s;

   // add a few elements
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);

   std::cout << "Stack should be 1234, bottom to top" << std::endl;

   // test empty and size
   if (s.empty())
      std::cout << "The stack is empty" << std::endl;
   else
      std::cout << "The stack is not empty" << std::endl;

   std::cout << "The stack size is " << s.size() << std::endl;

   while (!s.empty())
   {
      std::cout << "Stack top is " << s.top() << std::endl;
      s.pop();
      std::cout << "Popped top element" << std::endl;
   }

   try {s.pop();}
   catch (stackEmpty message)
   {
      std::cout << "Last pop failed " << std::endl;
      message.outputMessage();
   }

   return 0;
}
