// author - sonaspy@outlook.com
// coding - utf_8
#ifndef __PRIORITY_QUEUE__
#define __PRIORITY_QUEUE__
#include "algorithms.h"
namespace dsa
{

template <class _Tp, class _Compare = less<_Tp>>
class priority_q
{
protected:
    vector<_Tp> _containter;
    _Compare _comp;
    int _size;

public:
    priority_q()
    {
        _size = 0;
    }
    inline void push(const _Tp &val)
    {
        _containter.push_back(val);
        __pushheap(_containter.begin(), _containter.end(), _comp);
    }
    inline void pop()
    {
        __popheap(_containter.begin(), _containter.end(), _comp);
        _containter.pop_back();
    }
    inline _Tp top() const
    {
        return _containter.front();
    }
    inline int size() const
    {
        return _containter.size();
    }
    inline bool empty() const
    {
        return _containter.empty();
    }
};
} // namespace dsa
#endif