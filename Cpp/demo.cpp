// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
template <typename T>
class sd;

template <typename T>
class sd
{
};
int fun(int &c) { return c; }
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int b[10] = {1, 2, 3, 4, 5, 6};
    vector<int> a(10), c(b, b + 6), d(b, b + 6), f(6);
    auto it = a.begin();
    copy(c.begin(), c.end(), it);
    return 0;
}