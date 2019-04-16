/******************************************************************************************

 ******************************************************************************************/

#include "queen.h"

bool collide ( int* solu, int k ) { //判断是否可以在当前行的第k列放置下一皇后
   nCheck++;
   for ( int i = 0; i < k; i++ ) {
      if ( solu[k] == solu[i] )       return true; //列
      if ( solu[k] - solu[i] == k - i ) return true; //对角线
      if ( solu[k] - solu[i] == i - k ) return true; //反对角线
   }
   return false;
}