
#ifndef __SET_UNION__
#define __SET_UNION__
#include <bits/stdc++.h>
using namespace std;
namespace dsa
{
class _set_union
{
public:
    int _size;
    vector<int> arr;
    _set_union()
    {
        arr = vector<int>(9999, -1);
    }
    void clear()
    {
        arr = vector<int>(9999, -1);
    }
    inline int find_root(int id)
    {
        return arr[id] == -1 ? id : arr[id] = find_root(arr[id]);
    }
    inline bool same(int v1, int v2)
    {
        return find_root(v1) == find_root(v2);
    }
    inline int size() { return _size; }
    inline void resize(int c) { _size = c; }
    inline void unite(int a, int b)
    {
        int ra = find_root(a), rb = find_root(b);
        if (ra != rb)
            arr[rb] = ra;
    }
    inline bool connected()
    {
        int cnt = 0;
        for (int i = 0; i < _size; i++)
            if (arr[i] == -1)
                cnt++;
        return cnt == 1;
    }
};
}; // namespace dsa

#endif
