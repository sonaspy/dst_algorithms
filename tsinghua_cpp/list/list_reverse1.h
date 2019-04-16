/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> void List<T>::reverse() { //前后倒置
   ListNodePosi(T) p = header; ListNodePosi(T) q = trailer; //头、尾节点
   for ( int i = 1; i < _size; i += 2 ) //（从首、末节点开始）由外而内，捉对地
      swap ( ( p = p->succ )->data, ( q = q->pred )->data ); //交换对称节点的数据项
}