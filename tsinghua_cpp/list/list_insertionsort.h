/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> //列表的插入排序算法：对起始于位置p的n个元素排序
void List<T>::insertionSort ( ListNodePosi(T) p, int n ) { //valid(p) && rank(p) + n <= size
   /*DSA*/printf ( "InsertionSort ...\n" );
   for ( int r = 0; r < n; r++ ) { //逐一为各节点
      insertA ( search ( p->data, r, p ), p->data ); //查找适当的位置并插入
      p = p->succ; remove ( p->pred ); //转向下一节点
   }
}