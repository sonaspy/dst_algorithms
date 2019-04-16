/******************************************************************************************

 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

int* statistics ( char* sample_text_file ) { //统计字符出现频率
   int* freq = new int[N_CHAR];  //以下统计需随机访问，故以数组记录各字符出现次数
   memset ( freq, 0, sizeof ( int ) * N_CHAR ); //清零
   FILE* fp = fopen ( sample_text_file, "r" ); //assert: 文件存在且可正确打开
   for ( char ch; 0 < fscanf ( fp, "%c", &ch ); ) //逐个扫描样本文件中的每个字符
      if ( ch >= 0x20 ) freq[ch - 0x20]++; //累计对应的出现次数
   fclose ( fp ); return freq;
}