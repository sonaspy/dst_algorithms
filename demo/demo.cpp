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
    vector<int> a(10);
    iota(a.begin(), a.end(), 0);
    a.push_back(4);
    __linear_insert(a.begin(), a.end() - 1, a.back());
    output_vec(a);
    return 0;
}