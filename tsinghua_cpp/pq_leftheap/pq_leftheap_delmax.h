/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> T PQ_LeftHeap<T>::delMax() { //基于合并操作的词条删除算法（当前队列非空）
   BinNodePosi(T) lHeap = _root->lc; //左子堆
   BinNodePosi(T) rHeap = _root->rc; //右子堆
   T e = _root->data; delete _root; _size--; //删除根节点
   _root = merge ( lHeap, rHeap ); //原左右子堆合并
//   if ( _root ) _root->parent = NULL; //若堆非空，还需相应设置父子链接
   return e; //返回原根节点的数据项
}