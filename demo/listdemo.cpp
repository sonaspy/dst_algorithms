// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 100
#include "../src/dsa.h"

#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<int> a(20);
    iota(a.begin(), a.end(), 0);
    link_list<int> ls;
    ls.build(a);
    ls.output();
    ls.__locate(15), ls.__locate(16);
    ls.output();
    return 0;
}