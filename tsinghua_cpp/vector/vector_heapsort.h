/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> void Vector<T>::heapSort ( Rank lo, Rank hi ) { //0 <= lo < hi <= size
   /*DSA*/printf ( "\tHEAPsort [%3d, %3d)\n", lo, hi );
   PQ_ComplHeap<T> H ( _elem + lo, hi - lo ); //将待排序区间建成一个完全二叉堆，O(n)
   while ( ! H.empty() ) //反复地摘除最大元并归入已排序的后缀，直至堆空
/*DSA*/{
      _elem[--hi] = H.delMax(); //等效于堆顶与末元素对换后下滤
/*DSA*/for ( int i = lo; i < hi; i++ ) print( H[i] ); print(_elem[hi]); printf("\n");
/*DSA*/}
}
