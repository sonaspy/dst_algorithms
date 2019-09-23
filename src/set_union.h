
#ifndef __setunion__
#define __setunion__
#include <vector>
using namespace std;
namespace dsa
{
class __setunion
{
protected:
    inline int __getRoot(int id)
    {
        return __union_arr[id] == -1 ? id : __union_arr[id] = __getRoot(__union_arr[id]);
    }
public:
    vector<int> __union_arr;
    __setunion(int n = 1000)
    {
        __union_arr = vector<int>(n, -1);
    }
    void clear()
    {
        fill(__union_arr.begin(), __union_arr.end(), -1);
    }

    inline bool connected(int v1, int v2)
    {
        return __getRoot(v1) == __getRoot(v2);
    }
    inline int size() { return __union_arr.size(); }
    inline void resize(int c) { __union_arr.resize(c); }
    inline void unite(int a, int b)
    {
        int ra = __getRoot(a), rb = __getRoot(b);
        if (ra != rb)
            __union_arr[rb] = ra;
    }
    inline bool connected()
    {
        int cnt = 0;
        for (int i = 0; i < _size; i++)
            if (__union_arr[i] == -1)
                cnt++;
        return cnt == 1;
    }
};
}; // namespace dsa

#endif
