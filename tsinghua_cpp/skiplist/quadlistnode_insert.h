/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> QlistNodePosi(T) //将e作为当前节点的后继、b的上邻插入Quadlist
QuadlistNode<T>::insertAsSuccAbove ( T const& e, QlistNodePosi(T) b = NULL ) {
   QlistNodePosi(T) x = new QuadlistNode<T> ( e, this, succ, NULL, b ); //创建新节点
   succ->pred = x; succ = x; //设置水平逆向链接
   if ( b ) b->above = x; //设置垂直逆向链接
   return x; //返回新节点的位置
}