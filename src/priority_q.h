// author - sonaspy@outlook.com
// coding - utf_8
#ifndef __HEAP__
#define __HEAP__
#include "functions.h"
namespace dsa
{

template <typename T>
class priority_q
{
protected:
    vector<T> data;
    int _size;

public:
    priority_q()
    {
        _size = 0;
    }
    inline void push(const T &val)
    {
        data.push_back(val);
        __pushheap(data.begin(), data.end());
    }
    inline void pop()
    {
        __popheap(data.begin(), data.end());
        data.pop_back();
    }
    inline T top() const
    {
        return data.front();
    }
    inline int size() const
    {
        return data.size();
    }
    inline bool empty() const
    {
        return data.empty();
    }
};
} // namespace dsa
#endif