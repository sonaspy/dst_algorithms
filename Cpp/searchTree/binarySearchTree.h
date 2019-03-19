// linked binary tree implementation of a binary search tree
// implements all dictionary and bsTree methods

#ifndef binarySearchTree_
#define binarySearchTree_

#include "bsTree.h"
#include "linkedBinaryTree.h"

using namespace std;

template <class K, class E>
class binarySearchTree : public bsTree<K, E>,
    public linkedBinaryTree<pair<const K, E> >
{
public:
    bool empty() const
    {
        return treeSize == 0;
    }
    int size() const
    {
        return treeSize;
    }
    pair<const K, E> *find(const K &theKey) const;
    void insert(const pair<const K, E> &thePair);
    void erase(const K &theKey);
    // additional method of bsTree
    void ascend()
    {
        inOrderOutput();
    }
};

template <class K, class E>
pair<const K, E> *binarySearchTree<K, E>::find(const K &theKey) const
{
    // Return pointer to matching pair.
    // Return NULL if no matching pair.
    // p starts at the root and moves through
    // the tree looking for an element with key theKey
    binaryTreeNode<pair<const K, E> > *p = root;
    while(p != NULL)
        {
            if(theKey < p->element.first)
                p = p->leftChild;
            else if (theKey > p->element.first)
                p = p->rightChild;
            else
                return &p->element;
        }
    // no matching pair
    return NULL;
}
template <class K, class E>
void binarySearchTree<K, E>::insert(const pair<const K, E> &thePair)
{
    binaryTreeNode<pair<const K, E> > *p = root,
                                       *pp = NULL;
    while(p != NULL)
        {
            pp = p;
            // move p to a child
            if (thePair.first < p->element.first)
                p = p->leftChild;
            else if (thePair.first > p->element.first)
                p = p->rightChild;
            else
                {
                    p->element.second = thePair.second;
                    return;
                }
        }
    // get a node for thePair and attach to pp
    binaryTreeNode<pair<const K, E>> *newNode = new binaryTreeNode<pair<const K, E>>(thePair);
    if (root != NULL) // the tree is not empty
        if (thePair.first < pp->element.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    else
        root = newNode;
    treeSize++;
}

template <class K, class E>
void binarySearchTree<K, E>::erase(const K &theKey)
{
    // Delete the pair, if any, whose key equals theKey.
    // search for node with key theKey
    binaryTreeNode<pair<const K, E> > *p = root,
                                       *pp = NULL;
    while(p != NULL && theKey != p->element.first)
        {
            pp = p;
            if(p->element.first > theKey)
                p = p->leftChild;
            else
                p = p->rightChild;
        }
    if(p == NULL) return;
    return; // no pair with key theKey
    if (p->leftChild != NULL && p->rightChild != NULL)
        {
            // two children
            binaryTreeNode<pair<const K, E> > *s = p->leftChild,
                                               *ps = p; // parent of s
            // walk the s
            while(s->rightChild != NULL)
                {
                    ps = s;
                    s = s->rightChild;
                }
            binaryTreeNode<pair<const K, E> > *q =
                new binaryTreeNode<pair<const K, E> >(s->element, p->leftChild, p->rightChild);
            if (pp == NULL)
                root = q;
            else if (p == pp->leftChild)
                pp->leftChild = q;
            else if (p == pp->rightChild)
                pp->rightChild = q;
            if(ps == p)
                q->leftChild = s->leftChild;
            // free s anyway.
            delete s;
        }
    else
        {
            binaryTreeNode<pair<const K, E> > *c;
            if(p->leftChild != NULL)
                c = p->leftChild;
            else
                c = p->rightChild;
            if(p == root)
                root = c;
            else
                {
                    if(p == pp->leftChild)
                        pp->leftChild = c;
                    else
                        pp->rightChild = c;
                }
        }
    treeSize--;
}

// overload << for pair
template <class K, class E>
ostream &operator<<(ostream &out, const pair<K, E> &x)
{
    out << x.first << ' ' << x.second;
    return out;
}

#endif