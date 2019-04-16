/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> int List<T>::deduplicate() { //剔除无序列表中的重复节点
   if ( _size < 2 ) return 0; //平凡列表自然无重复
   int oldSize = _size; //记录原规模
   ListNodePosi(T) p = header; Rank r = 0; //p从首节点开始
   while ( trailer != ( p = p->succ ) ) { //依次直到末节点
      ListNodePosi(T) q = find ( p->data, r, p ); //在p的r个（真）前驱中查找雷同者
      q ? remove ( q ) : r++; //若的确存在，则删除之；否则秩加一
   } //assert: 循环过程中的任意时刻，p的所有前驱互不相同
   return oldSize - _size; //列表规模变化量，即被删除元素总数
}