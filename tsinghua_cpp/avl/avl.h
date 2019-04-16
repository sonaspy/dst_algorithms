/******************************************************************************************

 ******************************************************************************************/

#pragma once

#include "../BST/BST.h" //基于BST实现AVL树
template <typename T>
class AVL : public BST<T>
{ //由BST派生AVL树模板类
public:
    BinNodePosi(T) insert(const T &e); //插入（重写）
    bool remove(const T &e);           //删除（重写）
    // BST::search()等其余接口可直接沿用
};

#include "AVL_implementation.h"