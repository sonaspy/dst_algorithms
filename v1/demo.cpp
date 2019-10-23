// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 1000000
#include <bits/stdc++.h>
#include "stddsa.h"
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    clock_t startTime, endTime;
    // srand(time(NULL));
    skiplist<int, int> sk1(INT_MAX);
    startTime = clock();
    pair<int, int> p;
    set<int> rbx;
    for (int i = 0; i < SIZE; i++)
    {
        p = make_pair(i, 0);
        sk1.insert(p);
    }
    endTime = clock();

    cout << sk1.level() << endl;
    // sk1.print(cout);
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}