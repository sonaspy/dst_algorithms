/******************************************************************************************

 ******************************************************************************************/

#pragma once

#include "..\vector\vector.h"

template <typename T> void checkOrder ( Vector<T> & V ) { //判断向量是否整体有序
   int unsorted = 0; //逆序计数器
   V.traverse ( CheckOrder<T> ( unsorted, V[0] ) ); //进行遍历
   if ( 0 < unsorted )
      printf ( "Unsorted with %d adjacent disordered pair(s)\n", unsorted );
   else
      printf ( "Sorted\n" );
}

//template <typename T> void checkOrder(Vector<T> & V) {
//   if (0 < V.disordered())
//      printf("Unsorted with %d adjacent disordered pair(s)\n", V.disordered());
//   else
//      printf("Sorted\n");
//}