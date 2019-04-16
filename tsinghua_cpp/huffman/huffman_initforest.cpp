/******************************************************************************************

 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

HuffForest* initForest ( int* freq ) { //根据频率统计表，为每个字符创建一棵树
   HuffForest* forest = new HuffForest; //以List实现的Huffman森林
   for ( int i = 0; i < N_CHAR; i++ ) { //为每个字符
      forest->insertAsLast ( new HuffTree ); //生成一棵树，并将字符及其频率
      forest->last()->data->insertAsRoot ( HuffChar ( 0x20 + i, freq[i] ) ); //存入其中
   }
   return forest;
}