/******************************************************************************************

 ******************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../_share/util.h"
#include "../UniPrint/print.h"
#include "../vector/vector.h"
#include "quickSelect.h"

int main ( int argc, char* argv[] ) { //基于快速划分的k选取算法测试
   if ( 2 > argc ) { printf ( "Usage: %s <n>\a\a\n", argv[0] ); return 1; }
   int n = atoi ( argv[1] );
   if ( n < 1 ) { printf ( "Invalid arguments\a\a\n" ); return 1; }
   srand ( ( unsigned int ) time ( NULL ) );
// 随机生成向量
   Vector<int> A; //以整型为例
   while ( A.size() < n ) //继续不断插入n，直至共有n个元素
      A.insert ( A.size(), rand() % n );
   print ( A );
// 计算众数
   quickSelect ( A, n / 2 ); print ( A );
// 通过排序进一步验证
   A.sort(); print ( A );
// 返回
   return 0;
}