// Huffman tree

#include <iostream>
#include "minHeap.h"
#include "../BinaryTree/linkedBinaryTree.h"
#include "huffmanNode.h"

using namespace std;

template <class T>
linkedBinaryTree<int> *huffmanTree(T weight[], int n)
{ // Generate Huffman tree with weights weight[1:n], n >= 1.
  // create an array of single node trees
  huffmanNode<T> *hfmList = new huffmanNode<T> [n+1];
  linkedBinaryTree<T> emptyTree;
  for(int i = 1; i <=n; i++){
    hfmList[i].weight = weight[i];
    hfmList[i].tree = new linkedBinaryTree<int>;
    hfmList[i].tree->makeTree(i, emptyTree, emptyTree);
  }
  minHeap<huffmanNode<T> > heap(1);
  heap.initialize(hfmList, n);

  huffmanNode<T> w, x, y;
  linkedBinaryTree<int> *z;
  for(int i = 1; i < n; i++){
    x = heap.top(); heap.pop();
    y = heap.top(); heap.pop();
    // combine into a single tree
    z = new linkedBinaryTree<int>;
    z->makeTree(0, *x.tree, *y.tree);
    w.weight = x.weight + y.weight;
    w.tree = z;
    heap.push(w);
    delete x.tree;
    delete y.tree;
  }
  return heap.top().tree;
}


int main(int argc, char const *argv[])
{
  /* code */
  int a[11];
  int n = 10;
  for (int i = 1; i <= n; i++)
    a[i] = 2 * i;
  linkedBinaryTree<int> *x = huffmanTree(a, n);
  x->postOrderOutput();
  return 0;
  return 0;
}
