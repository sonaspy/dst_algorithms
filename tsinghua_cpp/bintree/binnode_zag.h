/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) BinNode<T>::zag() { //逆时针旋转
   BinNodePosi(T) rChild = rc;
   rChild->parent = this->parent;
   if ( rChild->parent )
      ( ( this == rChild->parent->lc ) ? rChild->parent->lc : rChild->parent->rc ) = rChild;
   rc = rChild->lc; if ( rc ) rc->parent = this;
   rChild->lc = this; this->parent = rChild;
   return rChild;
}
