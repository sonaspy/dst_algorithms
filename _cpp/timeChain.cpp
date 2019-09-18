// Chain run times

#include <iostream>
#include <time.h>
#include "chain.h"

using namespace std;

typedef chain<int> listType;
int main()
{
   double clocksPerMillis = double(CLOCKS_PER_SEC) / 1000;
                      // clock ticks per millisecond
   listType* s = NULL;

   // best-case test
   std::cout << "Best-case times in progress" << std::endl;
   int n = 50000;

   // insert n elements
   int m = 500;

   clock_t startTime = clock();
   for (int j = 0; j < m; j++)
   {
      delete s;
      s = new listType();
      for (int i = 0; i < n; i++)
        s->insert(0,i);
   }

   double elapsedTime = (clock() - startTime)/clocksPerMillis/m;
   std::cout << n << " inserts took " << elapsedTime << " ms" << std::endl;

   double insertTime = elapsedTime;

   // time get 
   m = 2;
   startTime = clock();
   for (int j = 0; j < m; j++)
      for (int i = 0; i < n; i++)
        s->get(i);

   elapsedTime = (clock() - startTime)/clocksPerMillis/m;
   std::cout << n << " gets took " << elapsedTime <<
                " ms" << std::endl;

   // time indexOf 
   startTime = clock();
   for (int i = 0; i < n; i++)
      s->indexOf(i);

   elapsedTime = (clock() - startTime)/clocksPerMillis;
   std::cout << n << " indexOfs took " << elapsedTime <<
                " ms" << std::endl;

   // worst-case time for indexOf 
   m = 5000;
   startTime = clock();
   for (int i = 0; i < m; i++)
      s->indexOf(n);

   elapsedTime = (clock() - startTime)/clocksPerMillis/m;
   std::cout << "Worst-case indexOf took " << elapsedTime <<
                " ms" << std::endl;


   // time erase
   m = 2000;
   startTime = clock();
   for (int j = 0; j < m; j++)
   {
      delete s;
      s = new listType();
      for (int i = 0; i < n; i++)
        s->insert(0,i);
      for (int i = n-1; i >= 0; i--)
        s->erase(0);
   }

   double elapsedTime1 = (clock() - startTime)/clocksPerMillis/m;

   elapsedTime = elapsedTime1 - insertTime;

   std::cout << n << " erases took " << elapsedTime <<
                " ms" << std::endl; 


   // average-case test
   std::cout << "Average-case times in progress" << std::endl;

   // random number overhead
   m = 5000000;
   startTime = clock();
   for (int i = 0; i < m; i++)
     int j = rand() % m;

   elapsedTime = clock() - startTime;
   std::cout << m << " randoms took " << elapsedTime << " ms" << std::endl;

   s = new listType();


   // insert n elements
   startTime = clock();
   for (int i = 1; i <= n; i++)
   {
     int j = rand() % i;
     s->insert(j,i);
   }

   elapsedTime = clock() - startTime;
   std::cout << n << " inserts took " << elapsedTime << " ms" << std::endl;



   // now remove them
   startTime = clock();
   for (int i = n; i > 0; i--)
   {
     int j = rand() % i;
     s->erase(j);
   }

   elapsedTime = clock() - startTime;
   std::cout << n << " erases took " << elapsedTime <<
                " ms" << std::endl;

// random inserts, worst-case deletes
   std::cout << "Random inserts, worst-case deletes" << std::endl;
   delete s;
   s = new listType();


   // insert n elements
   startTime = clock();
   for (int i = 1; i <= n; i++)
   {
     int j = rand() % i;
     s->insert(j,i);
   }

   elapsedTime = clock() - startTime;
   std::cout << n << " inserts took " << elapsedTime << " ms" << std::endl;



   // now remove them
   startTime = clock();
   for (int i = n-1; i >= 0; i--)
     s->erase(i);

   elapsedTime = clock() - startTime;
   std::cout << n << " erases took " << elapsedTime <<
                " ms" << std::endl;


   // worst-case test
   std::cout << "Worst-case times in progress" << std::endl;
   delete s;
   s = new listType();


   // insert n elements
   startTime = clock();
   for (int i = 0; i < n; i++)
     s->insert(i,i);

   elapsedTime = clock() - startTime;
   std::cout << n << " inserts took " << elapsedTime << " ms" << std::endl;



   // now remove them
   startTime = clock();
   for (int i = n-1; i >= 0; i--)
     s->erase(i);

   elapsedTime = clock() - startTime;
   std::cout << n << " erases took " << elapsedTime <<
                " ms" << std::endl;

   return 0;
}
