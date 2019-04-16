/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) & Splay<T>::search ( const T& e ) { //在伸展树中查找e
   BinNodePosi(T) p = searchIn ( _root, e, _hot = NULL );
   _root = splay ( p ? p : _hot ); //将最后一个被访问的节点伸展至根
   return _root;
} //与其它BST不同，无论查找成功与否，_root都指向最后被访问的节点