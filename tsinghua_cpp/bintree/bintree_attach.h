/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> //二叉树子树接入算法：将S当作节点x的左子树接入，S本身置空
BinNodePosi(T) BinTree<T>::attachAsLC ( BinNodePosi(T) x, BinTree<T>* &S ) { //x->lc == NULL
   if ( x->lc = S->_root ) x->lc->parent = x; //接入
   _size += S->_size; updateHeightAbove ( x ); //更新全树规模与x所有祖先的高度
   S->_root = NULL; S->_size = 0; release ( S ); S = NULL; return x; //释放原树，返回接入位置
}

template <typename T> //二叉树子树接入算法：将S当作节点x的右子树接入，S本身置空
BinNodePosi(T) BinTree<T>::attachAsRC ( BinNodePosi(T) x, BinTree<T>* &S ) { //x->rc == NULL
   if ( x->rc = S->_root ) x->rc->parent = x; //接入
   _size += S->_size; updateHeightAbove ( x ); //更新全树规模与x所有祖先的高度
   S->_root = NULL; S->_size = 0; release ( S ); S = NULL; return x; //释放原树，返回接入位置
}