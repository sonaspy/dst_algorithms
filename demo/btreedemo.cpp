// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 1000
#include "../src/stddsa.h"
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 10000; });
    iota(b, b + SIZE, 0);
    vector<int> a(b, b + SIZE);
    btree<int> bt(4);
    bt.build(a);
    clock_t startTime, endTime;
    //bt.printTree();
    startTime = clock();
    cout << bt.root() << endl;
    string s;
    int key1 = 100, key2 = 102, c;
    char cc;

    for (int i = key1; i <= key1; i++)
    {
        cout << bt.search(i) << endl;
    }

    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}