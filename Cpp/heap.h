// author - sonaspy@outlook.com
// coding - utf_8
#ifndef __HEAP__
#define __HEAP__

#include <bits/stdc++.h>
namespace dsa
{

template <typename T>
class heap
{
    // data[1....n] data[0] = INT_MAX
protected:
    vector<T> data;
    int _size;

    void __percDown(int pos)
    {
        T val = data[pos];
        int up = pos, down = 2 * pos;
        for (; down <= _size; up = down, down *= 2)
        {
            if (down < _size && data[down] < data[down + 1])
                ++down;
            if (data[down] > val)
                data[up] = data[down];
            else
                break;
        }
        data[up] = val;
    }

    void __buildHeap()
    {
        int i;
        for (i = _size / 2; i; --i)
            __percDown(i);
    }

public:
    heap()
    {
        _size = 0;
    }
    void push(const T &x)
    {
        data.push_back(x);
        _size++;
        int i = _size;
        for (; data[i / 2] < x; i /= 2)
            data[i] = data[i / 2];
        data[i] = x;
    }
    void pop()
    {
        if (_size == 1)
            return;
        iter_swap(data.begin() + 1, data.end() - 1);
        data.pop_back();
        _size--;
        __percDown(1);
    }
    T top()
    {
        return data[1];
    }
    int size()
    {
        return _size;
    }
    void build(vector<T> &a)
    {
        data.push_back(INT_MAX);
        data.insert(data.end(), a.begin(), a.end());
        _size = a.size();
        __buildHeap();
    }
};
} // namespace dsa
#endif