#ifndef __SKIPLIST__
#define __SKIPLIST__

#include <math.h>
#include "dictionary.h"
#include "myExceptions.h"

using namespace std;

template <class _Key, class _Val>
struct __snode
{
    typedef pair<_Key, _Val> _Entry;
    typedef __snode<_Key, _Val> *__snode_ptr;

    _Entry element;
    __snode_ptr *next; // 1D array of pointers

    __snode(_Entry &__entry, int size = 0) : element(__entry) { next = new __snode_ptr[size]; }
    ~__snode() { delete[] next; }
};

template <class _Key, class _Val>
class skiplist : public dictionary<_Key, _Val>
{
protected:
    typedef __snode<_Key, _Val> *__snode_ptr;
    typedef pair<_Key, _Val> _Entry;

public:
    int level() { return _level; }
    skiplist(_Key __max_key = _Key(), int __max_size = 10000000)
    {
        // Constructor for skip lists with keys smaller than __max_key
        _max_level = (int)ceil(logf((double)__max_size) / logf(1 / 0.5)) - 1;
        _level = 0; // initial number of _level
        _size = 0;
        _end_key = __max_key;

        _Entry _end_entry;
        _end_entry.first = _end_key;
        _begin = new __snode<_Key, _Val>(_end_entry, _max_level + 1);
        _end = new __snode<_Key, _Val>(_end_entry);
        _last = new __snode_ptr[_max_level + 1];

        // header points to tail at all _level as lists are empty
        for (int i = 0; i <= _max_level; i++)
            _begin->next[i] = _end;
    }
    ~skiplist()
    {
        __snode_ptr nextNode;
        // delete all nodes by following level 0 chain
        while (_begin != _end)
        {
            nextNode = _begin->next[0];
            delete _begin;
            _begin = nextNode;
        }
        delete _end;
        delete[] _last;
    }

    void clear()
    {
        __snode_ptr nextNode = _begin->next[0], tmp;
        while (nextNode != _end)
        {
            tmp = nextNode;
            nextNode = nextNode->next[0];
            delete tmp;
        }
        for (int i = 0; i <= _max_level; i++)
            _begin->next[i] = _end;
        _size = 0;
        _level = 0;
    }

    int size() { return _size; }
    bool empty() { return _size == 0; }
    _Entry *find(_Key &theKey)
    {
        if (theKey >= _end_key)
            return nullptr; // no matching pair possible

        __snode_ptr pre_node = _begin;
        for (int i = _level; i >= 0; i--) // go down _level
            while (pre_node->next[i]->element.first < theKey)
                pre_node = pre_node->next[i];

        if (pre_node->next[0]->element.first == theKey)
            return &pre_node->next[0]->element;

        return nullptr; // no matching pair
    }

    void erase(_Key &theKey)
    {
        // Delete the pair, if any, whose key equals theKey.
        if (theKey >= _end_key) // too large
            return;

        __snode_ptr theNode = __search(theKey);
        if (theNode->element.first != theKey) // not present
            return;

        // delete node from skip list
        for (int i = 0; i <= _level && _last[i]->next[i] == theNode; i++)
            _last[i]->next[i] = theNode->next[i];

        // update _level
        while (_level > 0 && _begin->next[_level] == _end)
            _level--;

        delete theNode;
        _size--;
    }

    void insert(_Entry &__entry)
    {
        if (__entry.first >= _end_key) // key too large
        {
            ostringstream s;
            s << "Key = " << __entry.first << " Must be < " << _end_key;
            throw illegalParameterValue(s.str());
        }

        __snode_ptr theNode = __search(__entry.first);
        if (theNode->element.first == __entry.first)
        { // update theNode->element.second
            theNode->element.second = __entry.second;
            return;
        }

        int theLevel = __decide_level(); // level of new node
        // fix theLevel to be <= _level + 1
        if (theLevel > _level)
        {
            theLevel = ++_level;
            _last[theLevel] = _begin;
        }

        __snode_ptr newNode = new __snode<_Key, _Val>(__entry, theLevel + 1);
        ++_size;
        for (int i = 0; i <= theLevel; i++)
        { // insert into level i chain
            newNode->next[i] = _last[i]->next[i];
            _last[i]->next[i] = newNode;
        }
    }
    void print(ostream &out)
    {
        for (__snode_ptr _walk = _begin->next[0]; _walk != _end; _walk = _walk->next[0])
            out << "(" << _walk->element.first << " : " << _walk->element.second << ") -> ";
        out << endl;
    }

protected:
    int __decide_level() // generate a random level number
    {
        int lev = 0;
        while (rand() & 1)
            ++lev;
        return (lev <= _max_level) ? lev : _max_level;
    }

    __snode_ptr __search(_Key &theKey)
    {
        // Return node that might contain theKey. position pre_node just before possible node with theKey
        __snode_ptr pre_node = _begin;
        for (int i = _level; i >= 0; i--)
        {
            while (pre_node->next[i]->element.first < theKey)
                pre_node = pre_node->next[i];
            _last[i] = pre_node; // _last level i node seen
        }
        return pre_node->next[0];
    }

    int _level,     // max current nonempty chain
        _size,      // number of pairs in dictionary
        _max_level; // max permissible chain level

    _Key _end_key; // a large key

    __snode_ptr _begin; // header node pointer
    __snode_ptr _end;   // tail node pointer
    __snode_ptr *_last; // _last[i] = _last node seen on level i
};

#endif