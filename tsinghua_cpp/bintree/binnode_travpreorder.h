/******************************************************************************************

 ******************************************************************************************/

#pragma once

/*DSA*/#include "../stack/Stack.h" //引入栈模板类
/*DSA*/#include "BinNode_TravPreorder_R.h"
/*DSA*/#include "BinNode_TravPreorder_I1.h"
/*DSA*/#include "BinNode_TravPreorder_I2.h"
template <typename T> template <typename VST> //元素类型、操作器
void BinNode<T>::travPre ( VST& visit ) { //二叉树先序遍历算法统一入口
   switch ( rand() % 3 ) { //此处暂随机选择以做测试，共三种选择
      case 1: travPre_I1 ( this, visit ); break; //迭代版#1
      case 2: travPre_I2 ( this, visit ); break; //迭代版#2
      default: travPre_R ( this, visit ); break; //递归版
   }
}