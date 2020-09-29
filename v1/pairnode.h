#ifndef pairNode_
#define pairNode_

using namespace std;

template <class K, class E>
struct pairNode {
    typedef pair<K, E> pairType;
    pairType element;
    pairNode<K, E> *next;

    pairNode(pairType &thePair) : element(thePair) {}
    pairNode(pairType &thePair, pairNode<K, E> *theNext) : element(thePair) {
        next = theNext;
    }
};