// place signal boosters

#include <iostream>
#include "booster.h"
#include "linkedBinaryTree.h"

using namespace std;

int tolerance = 3;

void Solving(binaryTreeNode<booster> *x, binaryTreeNode<booster> *child)
{
    if (child != NULL)
        {
            int degradation = child->element.degradeToLeaf +
                              child->element.degradeFromParent;
            if (degradation > tolerance)
                {
                    child->element.boosterHere = true;
                    x->element.degradeToLeaf = child->element.degradeFromParent;
                }
            else
                x->element.degradeToLeaf = degradation;
        }
}

void placeBoosters(binaryTreeNode<booster> *x)
{
    // Compute degradation at *x. Place booster
    // here if degradation exceeds tolerance.
    x->element.degradeToLeaf = 0;
    Solving(x, x->leftChild);
    Solving(x, x->rightChild);
}

int main(void)
{
    booster a, b;
    a.degradeFromParent = 2;
    a.degradeToLeaf = 0;
    a.boosterHere = 0;
    b.degradeFromParent = 1;
    b.degradeToLeaf = 0;
    b.boosterHere = 0;
    linkedBinaryTree<booster> t, u, v, w, x, y;
    u.makeTree(a, x, x);
    v.makeTree(b, u, x);
    u.makeTree(a, x, x);
    w.makeTree(a, u, x);
    b.degradeFromParent = 3;
    u.makeTree(b, v, w);
    v.makeTree(a, x, x);
    b.degradeFromParent = 3;
    w.makeTree(b, x, x);
    y.makeTree(a, v, w);
    w.makeTree(a, x, x);
    t.makeTree(b, y, w);
    b.degradeFromParent = 0;
    v.makeTree(b, t, u);
    v.postOrder(placeBoosters);
    v.postOrderOutput();
    return 0;
}
