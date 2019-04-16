/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> void List<T>::reverse() { //前后倒置
   if ( _size < 2 ) return; //平凡情况
   for ( ListNodePosi(T) p = header; p; p = p->pred ) //自前向后，依次
      swap ( p->pred, p->succ ); //交换各节点的前驱、后继指针
   swap ( header, trailer ); //头、尾节点互换
}