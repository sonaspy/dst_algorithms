/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> int List<T>::uniquify() { //成批剔除重复元素，效率更高
   if ( _size < 2 ) return 0; //平凡列表自然无重复
   int oldSize = _size; //记录原规模
   ListNodePosi(T) p = first(); ListNodePosi(T) q; //p为各区段起点，q为其后继
   while ( trailer != ( q = p->succ ) ) //反复考查紧邻的节点对(p, q)
      if ( p->data != q->data ) p = q; //若互异，则转向下一区段
      else remove ( q ); //否则（雷同），删除后者
   return oldSize - _size; //列表规模变化量，即被删除元素总数
}