/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) BinNode<T>::zig() { //顺时针旋转
   BinNodePosi(T) lChild = lc;
   lChild->parent = this->parent;
   if ( lChild->parent )
      ( ( this == lChild->parent->rc ) ? lChild->parent->rc : lChild->parent->lc ) = lChild;
   lc = lChild->rc; if ( lc ) lc->parent = this;
   lChild->rc = this; this->parent = lChild;
   return lChild;
}
