/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> //在有序列表内节点p（可能是trailer）的n个（真）前驱中，找到不大于e的最后者
ListNodePosi(T) List<T>::search ( T const& e, int n, ListNodePosi(T) p ) const {
// assert: 0 <= n <= rank(p) < _size
   /*DSA*/printf ( "searching for " ); print ( e ); printf ( " :\n" );
   while ( 0 <= n-- ) //对于p的最近的n个前驱，从右向左逐个比较
      /*DSA*/{ printf ( "  <%4d>", p->pred->data );
      if ( ( ( p = p->pred )->data ) <= e ) break; //直至命中、数值越界或范围越界
      /*DSA*/} printf ( "\n" );
// assert: 至此位置p必符合输出语义约定――尽管此前最后一次关键码比较可能没有意义（等效于与-inf比较）
   return p; //返回查找终止的位置
} //失败时，返回区间左边界的前驱（可能是header）――调用者可通过valid()判断成功与否