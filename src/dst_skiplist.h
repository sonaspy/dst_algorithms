#ifndef __SKIPLIST__
#define __SKIPLIST__

#include <math.h>

__DST_BEGIN_NAMESPACE

template <class _Key, class _Val>
struct __snode
{
    typedef pair<_Key, _Val> _Entry;
    typedef __snode<_Key, _Val> *__snode_ptr;

    _Entry _entry;
    int _height;
    __snode_ptr *__m_next; // 1D array of pointers

    __snode(_Entry &e, int __size = 0) : _entry(e)
    {
        __m_next = new __snode_ptr[__size];
        _height = __size;
    }
    ~__snode() { delete[] __m_next; }
};

template <class _Key, class _Val>
class __sklist_iterator
{
protected:
    typedef __snode<_Key, _Val> *__snode_ptr;
    typedef pair<_Key, _Val> &refrence_of_entry;
    typedef __sklist_iterator __self;
    __snode_ptr __m_cur;

public:
    __sklist_iterator(__snode_ptr p) : __m_cur(p) {}

    refrence_of_entry operator*() { return __m_cur->_entry; }
    __self &operator++()
    {
        __m_cur = __m_cur->__m_next[0];
        return *this;
    }
    __self operator++(int)
    {
        __self __tmp = *this;
        ++*this;
        return __tmp;
    }
    bool operator==(__self &__x) const { return __m_cur == __x.__m_cur; }
    bool operator!=(__self &__x) const { return __m_cur != __x.__m_cur; }
};

template <class _Key, class _Val>
class skiplist
{
protected:
    typedef __snode<_Key, _Val> *__snode_ptr;
    typedef __snode<_Key, _Val> __snode_base;
    typedef __sklist_iterator<_Key, _Val> iterator;
    typedef pair<_Key, _Val> _Entry;

public:
    int level() { return _level; }
    int size() { return _size; }
    bool empty() { return _size == 0; }

    skiplist(_Key __max_key = _Key(), int __max_size = 10000000)
    {
        // Constructor for skip lists with keys smaller than __max_key
        _max_level = (int)ceil(logf((double)__max_size) / logf(1 / 0.5)) - 1;
        _level = 0; // initial number of _level
        _size = 0;
        _end_key = __max_key;

        _Entry _end_entry;
        _end_entry.first = _end_key;
        _begin = new __snode_base(_end_entry, _max_level + 1);
        _end = new __snode_base(_end_entry);
        _last = new __snode_ptr[_max_level + 1];

        // header points to tail at all _level as lists are empty
        fill(_begin->__m_next, _begin->__m_next + _max_level + 1, _end);
    }
    ~skiplist()
    {
        __snode_ptr __m_next_node;
        // delete all nodes by following level 0 chain
        while (_begin != _end)
        {
            __m_next_node = _begin->__m_next[0];
            delete _begin;
            _begin = __m_next_node;
        }
        delete _end;
        delete[] _last;
    }

    void clear()
    {
        __snode_ptr __m_next_node = _begin->__m_next[0], tmp;
        while (__m_next_node != _end)
        {
            tmp = __m_next_node;
            __m_next_node = __m_next_node->__m_next[0];
            delete tmp;
        }
        for (int i = 0; i <= _max_level; i++)
            _begin->__m_next[i] = _end;
        _size = 0;
        _level = 0;
    }

    _Entry *get(_Key &the_key)
    {
        if (the_key >= _end_key)
            return nullptr; // no matching pair possible

        __snode_ptr pre_node = _begin;
        for (int i = _level; i >= 0; i--) // go down _level
            while (pre_node->__m_next[i]->_entry.first < the_key)
                pre_node = pre_node->__m_next[i];

        if (pre_node->__m_next[0]->_entry.first == the_key)
            return &pre_node->__m_next[0]->_entry;

        return nullptr; // no matching pair
    }

    inline bool count(_Key &the_key) { return get(the_key) != nullptr; }

    void erase(_Key &the_key)
    {
        // Delete the pair, if any, whose key equals the_key.
        if (the_key >= _end_key) // too large
            return;

        __snode_ptr __the_node = __search(the_key);
        if (__the_node->_entry.first != the_key) // not present
            return;

        // delete node from skip list
        for (int i = 0; i <= _level && _last[i]->__m_next[i] == __the_node; i++)
            _last[i]->__m_next[i] = __the_node->__m_next[i];

        // update _level
        while (_level > 0 && _begin->__m_next[_level] == _end)
            _level--;

        delete __the_node;
        _size--;
    }

    void insert(_Entry &__entry)
    {
        if (__entry.first >= _end_key) // key too large
        {
            return;
        }

        __snode_ptr __the_node = __search(__entry.first);
        if (__the_node->_entry.first == __entry.first)
        { // update __the_node->_entry.second
            __the_node->_entry.second = __entry.second;
            return;
        }

        int __the_level = __decide_level();
        // fix __the_level to be <= _level + 1
        if (__the_level > _level)
        {
            __the_level = ++_level;
            _last[__the_level] = _begin;
        }

        __snode_ptr new_node = new __snode_base(__entry, __the_level + 1);
        ++_size;
        for (int i = 0; i <= __the_level; i++)
        { // insert into level i chain
            new_node->__m_next[i] = _last[i]->__m_next[i];
            _last[i]->__m_next[i] = new_node;
        }
    }
    inline void insert(_Key k, _Val v)
    {
        _Entry e = _Entry(k, v);
        insert(e);
    }
    inline void insert(_Key &k, _Val &v)
    {
        _Entry e = _Entry(k, v);
        insert(e);
    }

    _Val &operator[](_Key key)
    {
        _Entry *p = get(key);
        if (p)
            return p->second;
        insert(key, _Val());
        return get(key)->second;
    }

    void print()
    {
        std::cout << "(begin h:" << _begin->_height << ")->";
        for (__snode_ptr _walk = _begin->__m_next[0]; _walk != _end; _walk = _walk->__m_next[0])
            std::cout << "(" << _walk->_entry.first << " h:" << _walk->_height << ")->";
        std::cout << "(end)" << endl;
    }
    iterator begin() { return iterator(_begin->__m_next[0]); }
    iterator end() { return iterator(_end); }

protected:
    int __decide_level() // generate a level number by 0.5 probability
    {
        int __lev = 0;
        while (rand() & 1)
            ++__lev;
        return (__lev <= _max_level) ? __lev : _max_level;
    }

    __snode_ptr __search(_Key &the_key)
    {
        __snode_ptr pre_node = _begin;
        for (int i = _level; i >= 0; i--)
        {
            while (pre_node->__m_next[i]->_entry.first < the_key)
                pre_node = pre_node->__m_next[i];
            _last[i] = pre_node; // _last level i node seen
        }
        return pre_node->__m_next[0];
    }

    int _level,     // max current nonempty chain
        _size,      // number of pairs in dictionary
        _max_level; // max permissible chain level

    _Key _end_key; // a large key

    __snode_ptr _begin; // header node pointer
    __snode_ptr _end;   // tail node pointer
    __snode_ptr *_last; // _last[i] = _last node seen on level i
};

__DST_END_NAMESPACE

#endif