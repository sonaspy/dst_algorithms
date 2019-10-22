#ifndef __SKIPLIST__
#define __SKIPLIST__

#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include "dictionary.h"
#include "myExceptions.h"

using namespace std;

template <class _Key, class _Val>
struct skipNode
{
    typedef pair<const _Key, _Val> pairType;
    typedef skipNode<_Key, _Val> *__skipnode_pointer;
    pairType element;
    __skipnode_pointer *next; // 1D array of pointers

    skipNode(const pairType &thePair, int size) : element(thePair) { next = new __skipnode_pointer[size]; }
};

template <class _Key, class _Val>
class skipList : public dictionary<_Key, _Val>
{
public:
    skipList(_Key, int maxPairs = 10000, float prob = 0.5);
    ~skipList();

    bool empty() const { return _size == 0; }
    int size() const { return _size; }
    pair<const _Key, _Val> *find(const _Key &) const;
    void erase(const _Key &);
    void insert(const pair<const _Key, _Val> &);
    void __output(ostream &out) const;

protected:
    float cutOff;      // used to decide level number
    int level() const; // generate a random level number
    int levels;        // max current nonempty chain
    int _size;         // number of pairs in dictionary
    int maxLevel;      // max permissible chain level
    _Key tailKey;      // a large key
    typedef skipNode<_Key, _Val> *__skipnode_pointer;
    __skipnode_pointer search(const _Key &) const;
    // search saving _last nodes seen
    __skipnode_pointer _headernode; // header node pointer
    __skipnode_pointer _tailnode;   // tail node pointer
    __skipnode_pointer *_last;      // _last[i] = _last node seen on level i
};

template <class _Key, class _Val>
skipList<_Key, _Val>::skipList(_Key largeKey, int maxPairs, float prob)
{ // Constructor for skip lists with keys smaller than largeKey and
    // size at most maxPairs. 0 < prob < 1.
    cutOff = prob * RAND_MAX;
    maxLevel = (int)ceil(logf((float)maxPairs) / logf(1 / prob)) - 1;
    levels = 0; // initial number of levels
    _size = 0;
    tailKey = largeKey;

    // create header & tail nodes and _last array
    pair<_Key, _Val> tailPair;
    tailPair.first = tailKey;
    _headernode = new skipNode<_Key, _Val>(tailPair, maxLevel + 1);
    _tailnode = new skipNode<_Key, _Val>(tailPair, 0);
    _last = new __skipnode_pointer[maxLevel + 1];

    // header points to tail at all levels as lists are empty
    for (int i = 0; i <= maxLevel; i++)
        _headernode->next[i] = _tailnode;
}

template <class _Key, class _Val>
skipList<_Key, _Val>::~skipList()
{ // Delete all nodes and array _last.
    __skipnode_pointer nextNode;

    // delete all nodes by following level 0 chain
    while (_headernode != _tailnode)
    {
        nextNode = _headernode->next[0];
        delete _headernode;
        _headernode = nextNode;
    }
    delete _tailnode;

    delete[] _last;
}

template <class _Key, class _Val>
pair<const _Key, _Val> *skipList<_Key, _Val>::find(const _Key &theKey) const
{ // Return pointer to matching pair.
    // Return NULL if no matching pair.
    if (theKey >= tailKey)
        return NULL; // no matching pair possible

    // position beforeNode just before possible node with theKey
    __skipnode_pointer beforeNode = _headernode;
    for (int i = levels; i >= 0; i--) // go down levels
        // follow level i pointers
        while (beforeNode->next[i]->element.first < theKey)
            beforeNode = beforeNode->next[i];

    // check if next node has theKey
    if (beforeNode->next[0]->element.first == theKey)
        return &beforeNode->next[0]->element;

    return NULL; // no matching pair
}

template <class _Key, class _Val>
int skipList<_Key, _Val>::level() const
{ // Return a random level number <= maxLevel.
    int lev = 0;
    while (rand() <= cutOff)
        lev++;
    return (lev <= maxLevel) ? lev : maxLevel;
}

template <class _Key, class _Val>
__skipnode_pointer skipList<_Key, _Val>::search(const _Key &theKey) const
{ // Search for theKey saving _last nodes seen at each
    // level in the array _last
    // Return node that might contain theKey.
    // position beforeNode just before possible node with theKey
    __skipnode_pointer beforeNode = _headernode;
    for (int i = levels; i >= 0; i--)
    {
        while (beforeNode->next[i]->element.first < theKey)
            beforeNode = beforeNode->next[i];
        _last[i] = beforeNode; // _last level i node seen
    }
    return beforeNode->next[0];
}

template <class _Key, class _Val>
void skipList<_Key, _Val>::insert(const pair<const _Key, _Val> &thePair)
{                                 // Insert thePair into the dictionary. Overwrite existing
                                  // pair, if any, with same key.
    if (thePair.first >= tailKey) // key too large
    {
        ostringstream s;
        s << "Key = " << thePair.first << " Must be < " << tailKey;
        throw illegalParameterValue(s.str());
    }

    // see if pair with theKey already present
    __skipnode_pointer theNode = search(thePair.first);
    if (theNode->element.first == thePair.first)
    { // update theNode->element.second
        theNode->element.second = thePair.second;
        return;
    }

    // not present, determine level for new node
    int theLevel = level(); // level of new node
    // fix theLevel to be <= levels + 1
    if (theLevel > levels)
    {
        theLevel = ++levels;
        _last[theLevel] = _headernode;
    }

    // get and insert new node just after theNode
    __skipnode_pointer newNode = new skipNode<_Key, _Val>(thePair, theLevel + 1);
    for (int i = 0; i <= theLevel; i++)
    { // insert into level i chain
        newNode->next[i] = _last[i]->next[i];
        _last[i]->next[i] = newNode;
    }

    _size++;
    return;
}

template <class _Key, class _Val>
void skipList<_Key, _Val>::erase(const _Key &theKey)
{                          // Delete the pair, if any, whose key equals theKey.
    if (theKey >= tailKey) // too large
        return;

    // see if matching pair present
    __skipnode_pointer theNode = search(theKey);
    if (theNode->element.first != theKey) // not present
        return;

    // delete node from skip list
    for (int i = 0; i <= levels && _last[i]->next[i] == theNode; i++)
        _last[i]->next[i] = theNode->next[i];

    // update levels
    while (levels > 0 && _headernode->next[levels] == _tailnode)
        levels--;

    delete theNode;
    _size--;
}

template <class _Key, class _Val>
void skipList<_Key, _Val>::__output(ostream &out) const
{ // Insert the dictionary pairs into the stream out.
    // follow level 0 chain
    for (__skipnode_pointer currentNode = _headernode->next[0];
         currentNode != _tailnode;
         currentNode = currentNode->next[0])
        out << currentNode->element.first << " " << currentNode->element.second << "  ";
}

// overload <<
template <class _Key, class _Val>
ostream &operator<<(ostream &out, const skipList<_Key, _Val> &x)
{
    x.__output(out);
    return out;
}

#endif
