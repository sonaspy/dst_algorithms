/******************************************************************************************

 ******************************************************************************************/

#pragma once

/*DSA*/#include "../_share/util.h"
/*DSA*/#include "../UniPrint/print.h"

/******************************************************************************************
 * PFC编码使用的数据结构
 ******************************************************************************************/
#include "../BinTree/BinTree.h" //用BinTree实现PFC树
typedef BinTree<char> PFCTree; //PFC树

#include "../Vector/Vector.h" //用Vector实现PFC森林
typedef Vector<PFCTree*> PFCForest; //PFC森林

#include "../Bitmap/Bitmap.h" //使用位图结构实现二进制编码串
#include "../Skiplist/Skiplist.h" //引入Skiplist式词典结构实现
typedef Skiplist<char, char*> PFCTable; //PFC编码表，词条格式为：(key = 字符, value = 编码串)

#define  N_CHAR  (0x80 - 0x20) //只考虑可打印字符
