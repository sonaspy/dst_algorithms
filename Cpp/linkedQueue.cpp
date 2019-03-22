// test linked queue

#include <iostream>
#include "linkedQueue.h"
#include "myExceptions.h"

using namespace std;

int main(void)
{
   linkedQueue<int> q;

   // add a few elements
   q.push(1);
   std::cout << "Queue back is " << q.back() << std::endl;
   q.push(2);
   std::cout << "Queue back is " << q.back() << std::endl;
   q.push(3);
   std::cout << "Queue back is " << q.back() << std::endl;
   q.push(4);
   std::cout << "Queue back is " << q.back() << std::endl;

   std::cout << "Queue should be 1234, front to back" << std::endl;

   // test empty and size
   if (q.empty())
      std::cout << "The queue is empty" << std::endl;
   else
      std::cout << "The queue is not empty" << std::endl;

   std::cout << "The queue size is " << q.size() << std::endl;

   while (!q.empty())
   {
      std::cout << "Queue front is " << q.front() << std::endl;
      q.pop();
      std::cout << "Popped front element" << std::endl;
   }

   try {q.pop();}
   catch (queueEmpty message)
   {
      std::cout << "Last pop failed " << std::endl;
      message.outputMessage();
   }

   return 0;
}
