// test array queue

#include <iostream>
#include "arrayQueue.h"
#include "myExceptions.h"

using namespace std;

int main(void)
{
   arrayQueue<int> q(4);

   // add a few elements
   q.push(1);
   std::cout << "Queue rear is " << q.back() << std::endl;
   q.push(2);
   std::cout << "Queue rear is " << q.back() << std::endl;
   q.push(3);
   std::cout << "Queue rear is " << q.back() << std::endl;
   q.push(4);
   std::cout << "Queue rear is " << q.back() << std::endl;

   std::cout << "Queue should be 1234, front to rear" << std::endl;

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

   // create a wraparound queue and do array doubling
   arrayQueue<int> r(4);
   r.push(1);
   r.push(2);
   r.push(3);
   r.pop();
   r.pop();
   r.push(4);
   r.push(5);
   r.push(6);
   r.push(7);

   std::cout << "Queue should be 34567, front to rear" << std::endl;

   // test empty and size
   if (r.empty())
      std::cout << "The queue is empty" << std::endl;
   else
      std::cout << "The queue is not empty" << std::endl;

   std::cout << "The queue size is " << r.size() << std::endl;

   while (!r.empty())
   {
      std::cout << "Queue front is " << r.front() << std::endl;
      r.pop();
      std::cout << "Popped front element" << std::endl;
   }

   return 0;
}
