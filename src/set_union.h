
#ifndef __setunion__
#define __setunion__
#include <vector>
using namespace std;
namespace dsa
{
class __setunion
{
public:
    int _size;
    vector<int> arr;
    __setunion(int thesize = 1000)
    {
        arr = vector<int>(thesize, -1);
    }
    void clear()
    {
        arr = vector<int>(9999, -1);
    }
    inline int find_root(int id)
    {
        return arr[id] == -1 ? id : arr[id] = find_root(arr[id]);
    }
    inline bool connected(int v1, int v2)
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
