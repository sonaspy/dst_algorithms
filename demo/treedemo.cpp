// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/dsa.h"

#define SIZE 20
using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));

    string s;
    clock_t startTime, endTime;
    int nm = 10;
    int c = 0, c0 = 0;
    int b[SIZE], n = SIZE;
    generate(b, b + n, [&]() { return rand() % 1000; });
    vector<int> a(b, b + n);
    rbtree<int> ax;
    ax.build(a);
    auto it = ax.end();
    for (; *it; it--)
        cout << (*it)->val << "->";
    cout << endl;
    ax.intrav([](binode_ptr<int> &p) { cout << p->val << "->"; });
    cout << endl;
    startTime = clock();
    ax.search(a[0]);
    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}