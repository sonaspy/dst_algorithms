/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> void PQ_ComplHeap<T>::heapify ( Rank n ) { //Floyd建堆算法，O(n)时间
   for ( int i = LastInternal ( n ); InHeap ( n, i ); i-- ) //自底而上，依次
/*DSA*/{
      percolateDown ( n, i ); //下滤各内部节点
/*DSA*/for ( int k = 0; k < n; k++ ) {
/*DSA*/  int kk = k; while ( i < kk ) kk = (kk - 1) / 2;
/*DSA*/  i == kk ? print(_elem[k]) : print("    " );
/*DSA*/}; printf("\n");
/*DSA*/}
}
