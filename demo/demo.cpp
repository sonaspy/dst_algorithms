// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include "../cpp/dsa.h"
#include<algorithm>
#define test() freopen("in", "r", stdin)
using namespace dsa;
using namespace std;

int fun(int &c) { return c; }
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<int> a(100);
    iota(a.begin(), a.end(), 1);
    cout << less<int>()(2,2);
    make_heap(a.begin(), a.end());
    return 0;
}