#ifndef __SKIPLIST__
#define __SKIPLIST__

/*
    This file contains the skiplist implementation.
    To use the skiplist, you must provide a max key,
    all keys which are larger than the maxkey will be ditched.
    If you choose the default maxkey, it probably won't work as you expected.
*/

#include <math.h>

__DST_BEGIN_NAMESPACE

template <class _Key, class _Val> struct __skiplist_node {
    typedef pair<_Key, _Val> _Entry;
    typedef __skiplist_node<_Key, _Val> *__node_Ptr;

    _Entry _entry;
    int _height;
    __node_Ptr *_M_nexts; // 1D array of pointers

    __skiplist_node(_Entry &e, int __size = 0) : _entry(e) {
        _M_nexts = new __node_Ptr[__size];
        _height = __size;
    }
    ~__skiplist_node() { delete[] _M_nexts; }
};

template <class _Key, class _Val> struct __skip_list_iterator {
    typedef __skiplist_node<_Key, _Val> __node;
    typedef __node *__node_Ptr;
    typedef pair<_Key, _Val> _Entry;
    typedef __skip_list_iterator __self;

    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef forward_iterator_tag iterator_category;
    typedef _Entry value_type;
    typedef _Entry *pointer;
    typedef _Entry &reference;

    __node_Ptr _M_this;

    __skip_list_iterator() {}
    __skip_list_iterator(__node_Ptr p) : _M_this(p) {}

    reference operator*() { return _M_this->_entry; }
    __self &operator++() {
        _M_this = _M_this->_M_nexts[0];
        return *this;
    }
    __self operator++(int) {
        __self __tmp = *this;
        ++*this;
        return __tmp;
    }
    bool operator==(__self &__x) const { return _M_this == __x._M_this; }
    bool operator!=(__self &__x) const { return _M_this != __x._M_this; }
};

template <class _Key, class _Val = int> class skiplist {
  protected:
    typedef __skiplist_node<_Key, _Val> __node;
    typedef __node *__node_Ptr;
    typedef pair<_Key, _Val> _Entry;

  public:
    typedef size_t size_type;
    typedef _Entry value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef ptrdiff_t difference_type;

    typedef __skip_list_iterator<_Key, _Val> iterator;
    typedef __skip_list_iterator<const _Key, const _Val> const_iterator;

    size_t level() { return _level; }
    size_t size() { return _size; }
    bool empty() { return _size == 0; }

    skiplist(_Key __max_key = _Key(), size_t __max_size = 10000000) {
        // Constructor for skip lists with keys smaller than __max_key
        _max_level = (size_t)ceil(logf((double)__max_size) / logf(1 / 0.5)) - 1;
        _level = 0; // initial number of _level
        _size = 0;
        __null_key = __max_key;

        _Entry __null_entry;
        __null_entry.first = __null_key;
        _M_start = new __node(__null_entry, _max_level + 1);
        _M_finish = new __node(__null_entry);
        __last_checked_ptrs = new __node_Ptr[_max_level + 1];

        // header points to tail at all _level as lists are empty
        fill(_M_start->_M_nexts, _M_start->_M_nexts + _max_level + 1,
             _M_finish);
    }
    ~skiplist() {
        __node_Ptr _M_next_node;
        // delete all nodes by following level 0 chain
        while (_M_start != _M_finish) {
            _M_next_node = _M_start->_M_nexts[0];
            delete _M_start;
            _M_start = _M_next_node;
        }
        delete _M_finish;
        delete[] __last_checked_ptrs;
    }

    void clear() {
        __node_Ptr _M_next_node = _M_start->_M_nexts[0], tmp;
        while (_M_next_node != _M_finish) {
            tmp = _M_next_node;
            _M_next_node = _M_next_node->_M_nexts[0];
            delete tmp;
        }
        for (int i = 0; i <= _max_level; i++) _M_start->_M_nexts[i] = _M_finish;
        _size = 0;
        _level = 0;
    }

    _Entry *get(_Key &the_key) {
        if (the_key >= __null_key)
            return nullptr; // no matching pair possible

        __pre_node = _M_start;
        for (int i = _level; i >= 0; i--) // go down _level
            while (__pre_node->_M_nexts[i]->_entry.first < the_key)
                __pre_node = __pre_node->_M_nexts[i];

        if (__pre_node->_M_nexts[0]->_entry.first == the_key)
            return &__pre_node->_M_nexts[0]->_entry;

        return nullptr; // no matching pair
    }

    inline bool count(_Key &the_key) { return get(the_key) != nullptr; }

    void erase(_Key &the_key) {
        // Delete the pair, if any, whose key equals the_key.
        if (the_key >= __null_key) // too large
            return;

        __node_Ptr __the_node = __search(the_key);
        if (__the_node->_entry.first != the_key) // not present
            return;

        // delete node from skip list
        for (int i = 0;
             i <= _level && __last_checked_ptrs[i]->_M_nexts[i] == __the_node;
             i++)
            __last_checked_ptrs[i]->_M_nexts[i] = __the_node->_M_nexts[i];

        // update _level
        while (_level > 0 && _M_start->_M_nexts[_level] == _M_finish) _level--;

        delete __the_node;
        _size--;
    }

    void insert(_Entry __entry) {
        if (__entry.first >= __null_key) // key too large
        {
            return;
        }

        __node_Ptr __the_node = __search(__entry.first);
        if (__the_node->_entry.first ==
            __entry.first) { // update __the_node->_entry.second
            __the_node->_entry.second = __entry.second;
            return;
        }

        size_t __the_level = __decide_level();
        // fix __the_level to be <= _level + 1
        if (__the_level > _level) {
            __the_level = ++_level;
            __last_checked_ptrs[__the_level] = _M_start;
        }

        __node_Ptr new_node = new __node(__entry, __the_level + 1);
        ++_size;
        for (int i = 0; i <= __the_level; i++) { // insert into level i chain
            new_node->_M_nexts[i] = __last_checked_ptrs[i]->_M_nexts[i];
            __last_checked_ptrs[i]->_M_nexts[i] = new_node;
        }
    }
    inline void insert(_Key k, _Val v) {
        _Entry e = _Entry(k, v);
        insert(e);
    }
    inline void insert(_Key &k, _Val &v) {
        _Entry e = _Entry(k, v);
        insert(e);
    }

    _Val &operator[](_Key key) {
        _Entry *p = get(key);
        if (p)
            return p->second;
        insert(key, _Val());
        return get(key)->second;
    }

    void print() {
        std::cout << "(begin h:" << _M_start->_height << ")->";
        for (__node_Ptr _walk = _M_start->_M_nexts[0]; _walk != _M_finish;
             _walk = _walk->_M_nexts[0])
            std::cout << "(" << _walk->_entry.first << " h:" << _walk->_height
                      << ")->";
        std::cout << "(end)" << endl;
    }
    iterator begin() { return iterator(_M_start->_M_nexts[0]); }
    iterator end() { return iterator(_M_finish); }

  protected:
    size_t __decide_level() // generate a level number by 0.5 probability
    {
        size_t __lev = 0;
        while (rand() & 1) ++__lev;
        return (__lev <= _max_level) ? __lev : _max_level;
    }

    __node_Ptr __search(_Key &the_key) {
        __pre_node = _M_start;
        for (int i = _level; i >= 0; i--) {
            while (__pre_node->_M_nexts[i]->_entry.first < the_key)
                __pre_node = __pre_node->_M_nexts[i];
            __last_checked_ptrs[i] =
                __pre_node; // __last_checked_ptrs level i node seen
        }
        return __pre_node->_M_nexts[0];
    }

    size_t _level;     // max current nonempty chain
    size_t _size;      // number of pairs in dictionary
    size_t _max_level; // max permissible chain level

    _Key __null_key; // a max key

    __node_Ptr _M_start;   // dummy header node pointer
    __node_Ptr _M_finish;  // dummy tail node pointer
    __node_Ptr __pre_node; // every time operate, remember the pre node.
    __node_Ptr *__last_checked_ptrs; // [i] = node seen on level i
};

__DST_END_NAMESPACE

#endif