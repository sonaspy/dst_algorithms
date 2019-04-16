/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> //遍历Quadlist，对各节点依次实施visit操作
void Quadlist<T>::traverse ( void ( *visit ) ( T& ) ) { //利用函数指针机制，只读或局部性修改
   QlistNodePosi(T) p = header;
   while ( ( p = p->succ ) != trailer ) visit ( p->data );
}

template <typename T> template <typename VST> //遍历Quadlist，对各节点依次实施visit操作
void Quadlist<T>::traverse ( VST& visit ) { //利用函数对象机制，可全局性修改
   QlistNodePosi(T) p = header;
   while ( ( p = p->succ ) != trailer ) visit ( p->data );
}