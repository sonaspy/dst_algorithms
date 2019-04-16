/******************************************************************************************

 ******************************************************************************************/

/*DSA*/#include "simu.h"

int bestWindow ( Queue<Customer> windows[], int nWin ) { //为新到顾客确定最佳队列
   int minSize = windows[0].size(), optiWin = 0; //最优队列（窗口）
   for ( int i = 1; i < nWin; i++ ) //在所有窗口中
      if ( minSize > windows[i].size() ) //挑选出
         { minSize = windows[i].size(); optiWin = i; } //队列最短者
   return optiWin; //返回
}