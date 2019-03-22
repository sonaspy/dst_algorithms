// test linked binary tree class

#include <iostream>
#include "linkedBinaryTree.h"

using namespace std;

int main(void)
{
   linkedBinaryTree<int> a,x,y,z;
   y.makeTree(1,a,a);
   z.makeTree(2,a,a);
   x.makeTree(3,y,z);
   y.makeTree(4,x,a);
   std::cout << "Number of nodes = ";
   std::cout << y.size() << std::endl;
   std::cout << "height = ";
   std::cout << y.height() << std::endl;
   std::cout << "Preorder sequence is ";
   y.preOrderOutput();
   std::cout << "Inorder sequence is ";
   y.inOrderOutput();
   std::cout << "Postorder sequence is ";
   y.postOrderOutput();
   std::cout << "Level order sequence is ";
   y.levelOrderOutput();

   return 0;
}
