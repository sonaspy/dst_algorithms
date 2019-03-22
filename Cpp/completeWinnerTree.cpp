// test winner tree class

#include <iostream>
#include "completeWinnerTree.h"
#include "player.h"

using namespace std;

void main(void)
{
   int n;
   std::cout << "Enter number of players, >= 2" << std::endl;
   std::cin >> n;
   if (n < 2)
      {std::cout << "Bad input" << std::endl;
       exit(1);}


   player *thePlayer = new player[n + 1];

   std::cout << "Enter player values" << std::endl;
   for (int i = 1; i <= n; i++)
   {
      std::cin >> thePlayer[i].key;
      thePlayer[i].id = i;
   }

   completeWinnerTree<player> *w = 
      new completeWinnerTree<player>(thePlayer, n);
   std::cout << "The winner tree is" << std::endl;
   w->output();

   thePlayer[2].key = 0;
   w->rePlay(2);
   std::cout << "Changed player 2 to zero, new tree is" << std::endl;
   w->output();

   thePlayer[3].key = -1;
   w->rePlay(3);
   std::cout << "Changed player 3 to -1, new tree is" << std::endl;
   w->output();

   thePlayer[7].key = 2;
   w->rePlay(7);
   std::cout << "Changed player 7 to 2, new tree is" << std::endl;
   w->output();
}
