// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 20
#include "../src/dsa.h"

#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    // generate(b, b + SIZE, [&]() { return rand() % 10; });
    vector<int> a(b, b + SIZE);
    iota(a.begin(), a.end(), 0);
    link_list<int> ls;
    ls.build(a);
    ls.print();
    ls.erase(19);
    ls.print();
    ls.pop_front();
    cout << ls.back() << endl;
    cout << ls.front() << endl;
    return 0;
}