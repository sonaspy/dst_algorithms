/******************************************************************************************

 ******************************************************************************************/

#include "../queen_brute_force_1/queen.h"

void place2Queens() { //2皇后剪枝算法
   int solu[2]; //解法
   for ( solu[0] = 0; solu[0] < 2; solu[0]++ )
      if ( !collide ( solu, 0 ) )
         for ( solu[1] = 0; solu[1] < 2; solu[1]++ )
            if ( !collide ( solu, 1 ) ) {
               nSolu++; displaySolution ( solu, 2 );
            }
}
