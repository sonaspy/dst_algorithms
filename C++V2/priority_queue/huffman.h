#pragma once

#include"../hashing/bitmap.h"
#include"../hashing/hashtable.h"
#include"../bintree/BinTree.h"

#ifndef huffman_
#define huffman_

#define N_CHAR (0x80 - 0x20)
#define HuffTree BinTree<HuffChar>
typedef Bitmap HuffCode;
typedef Hashtable<char, char*> HuffTable;  


struct HuffChar
{
    char ch;
    int weight;
    HuffChar(char c = '^', int w = 0) : ch(c), weight(w){};
    bool operator<(HuffChar const &hc) { return weight > hc.weight; }
    bool operator==(HuffChar const &hc) { return weight == hc.weight; }
};





#endif