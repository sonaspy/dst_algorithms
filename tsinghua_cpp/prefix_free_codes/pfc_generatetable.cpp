/******************************************************************************************

 ******************************************************************************************/

/*DSA*/#include "PFC.h"

void generateCT //通过遍历获取各字符的编码
( Bitmap* code, int length, PFCTable* table, BinNodePosi ( char ) v ) {
   if ( IsLeaf ( *v ) ) //若是叶节点
      { table->put ( v->data, code->bits2string ( length ) ); return; }
   if ( HasLChild ( *v ) ) //Left = 0
      { code->clear ( length ); generateCT ( code, length + 1, table, v->lc ); }
   if ( HasRChild ( *v ) ) //right = 1
      { code->set ( length ); generateCT ( code, length + 1, table, v->rc ); }
}

PFCTable* generateTable ( PFCTree* tree ) { //构造PFC编码表
   PFCTable* table = new PFCTable; //创建以Skiplist实现的编码表
   Bitmap* code = new Bitmap; //用于记录RPS的位图
   generateCT ( code, 0, table, tree->root() ); //遍历以获取各字符（叶节点）的RPS
   release ( code ); return table; //释放编码位图，返回编码表
}