// author -sonaspy@outlook.com
// coding - utf_8

#include "../src/functions.h"
#define test() freopen("in", "r", stdin)
using namespace std;
using namespace dsa;

template <class T>
struct node
{
    int i;
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<int> a, b(10, 10);
    a.reserve(100);
    copy(b.begin(), b.end(), a.begin());
    //iota(a.begin(), a.end(), 0);
    output_vec(a);
    cout << a[14];
    return 0;
}