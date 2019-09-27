
#ifndef __Union__
#define __Union__
#include <vector>
using namespace std;
namespace dsa
{
class __Union
{
protected:
    inline int __getRoot(int id)
    {
        return __union_arr[id] < 0 ? id : __union_arr[id] = __getRoot(__union_arr[id]);
    }
public:
    vector<int> __union_arr;
    __Union(int n = 1000)
    {
        __union_arr = vector<int>(n, -1);
    }
    void clear()
    {
        fill(__union_arr.begin(), __union_arr.end(), -1);
    }
    inline int size() { return __union_arr.size(); }
    inline void resize(int c) { __union_arr.resize(c); }
    inline void unite(int a, int b)
    {
        int ra = __getRoot(a), rb = __getRoot(b);
        if (ra != rb)
        {
            if (__union_arr[ra] <= __union_arr[rb])
            {
                __union_arr[ra] += __union_arr[rb];
                __union_arr[rb] = ra;
            }
            else
            {
                __union_arr[rb] += __union_arr[ra];
                __union_arr[ra] = rb;
            }
        }
    }
    inline bool connected()
    {
        int cnt = 0;
        for (int i = 0; i < __union_arr.size(); i++)
            if (__union_arr[i] == -1)
                cnt++;
        return cnt == 1;
    }
    inline bool connected(int v1, int v2)
    {
        return __getRoot(v1) == __getRoot(v2);
    }
};
}; // namespace dsa

#endif
