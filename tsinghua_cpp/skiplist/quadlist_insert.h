/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> QlistNodePosi(T) //将e作为p的后继、b的上邻插入Quadlist
Quadlist<T>::insertAfterAbove ( T const& e, QlistNodePosi(T) p, QlistNodePosi(T) b = NULL )
{  _size++; return p->insertAsSuccAbove ( e, b );  } //返回新节点位置（below = NULL）