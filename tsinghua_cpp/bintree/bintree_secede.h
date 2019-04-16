/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> //二叉树子树分离算法：将子树x从当前树中摘除，将其封装为一棵独立子树返回
BinTree<T>* BinTree<T>::secede ( BinNodePosi(T) x ) { //assert: x为二叉树中的合法位置
   FromParentTo ( *x ) = NULL; //切断来自父节点的指针
   updateHeightAbove ( x->parent ); //更新原树中所有祖先的高度
   BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL; //新树以x为根
   S->_size = x->size(); _size -= S->_size; return S; //更新规模，返回分离出来的子树
}